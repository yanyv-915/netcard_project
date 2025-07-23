#include"card.h"
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;
Card::Card(string id_,string password_,string owner_) {
    this->id=id_;
    this->owner=owner_;
    this->password=password_;
    this->loginTime=time(nullptr);
    this->balance=0.0;
    this->isOnline=false;
}
ostream& operator<<(ostream& os,const Card& card){
    os<<"账号："<<card.id<<"\n"
      <<"持有者："<<card.owner<<"\n"
      <<"密码："<<card.password<<"\n"
      <<"余额："<<card.balance<<"\n"
      <<"是否在线："<<(card.isOnline?"是":"否")<<"\n";
    if(card.isOnline){
        os<<"登录时间："<<asctime(localtime(&card.loginTime));
    }
    os<<"------------------------------\n";
    return os;
}
void CardManager::addCard(){
    loadFromFile();
    cout<<"请输入您的账号\n";
    string id;
    cin>>id;
    cout<<"请输入您的密码\n";
    string password;
    cin>>password;
    cout<<"请输入您的姓名\n";
    string owner;
    cin>>owner;
    cards.push_back(Card(id,password,owner));
    cout<<"添加完成！信息如下\n";
    cout << left
         << setw(20) << "owner"
         << setw(20) << "id"
         << setw(12) << "password" << endl;
    cout << left
         << setw(20) << owner
         << setw(20) << id
         << setw(12) << password << endl;
    saveToFile();
    cout<<"请妥善保管您的账号和密码！\n";
}
Card* CardManager::findCard(){
    loadFromFile();
    cout<<"请输入账号：\n";
    string id;
    cin>>id;
    cout<<"请输入密码：\n";
    string password;
    cin>>password;
    bool found=false;
    for(auto &c:cards){
        if(c.id==id&&c.password==password){
            return &c;
        }
    }
    cout<<"未找到该卡，请重新检查输入！\n";
    return nullptr;
}
void CardManager::deleteCard(){
    loadFromFile();
    cout<<"请输入您想删除的账号：\n";
    string id;
    cin>>id;
    for(auto it=cards.begin();it!=cards.end();it++){
        if(it->id==id){
            cards.erase(it);
            cout<<"删除完毕！";
            saveToFile();
            return;
        }
    }
    cout<<"未查到该卡，请检查输入！\n";
}
void CardManager::saveToFile(const string& fileneme){
    ofstream ofs(fileneme);
    if(!ofs){
        std::cerr<<"无法打开文件保存卡信息\n";
        return;
    }
    for(const auto& c:cards){
        c.saveToFile(ofs);
    }
    ofs.close();
    cout<<"卡信息保存成功！\n";
}
void CardManager::loadFromFile(const string& fileneme){
    ifstream ifs(fileneme);
    if(!ifs){
        cerr<<"无法打开文件读取卡信息，或文件不存在!\n";
        return;
    }
    cards.clear();
    while (ifs.peek()!=EOF){
        Card c=Card::loadFromFile(ifs);
        if(ifs) cards.push_back(c);
    }
    ifs.close();
    cout<<"卡信息读取完毕，共读取 "<<cards.size()<<" 张卡。\n";
}
void Card::login(CardManager& cm){
    Card* c=cm.findCard();
    if(c==NULL){
        return;
    }
    if(c->isOnline==true){
        cout<<"该卡正在登录！\n";
        return;
    }
    c->loginTime=time(nullptr);
    c->isOnline=true;
    cout<<"登录成功！\n";
    cout<<*c<<"\n";
    cm.saveToFile();
}
void Card::logout(CardManager& cm){
    Card* c=cm.findCard();
    if(c==NULL){
        return;
    }
    if(c->isOnline==false){
        cout<<"该卡未登录，无法下机！\n";
    }
    time_t now=time(nullptr);
    double secondUsed=difftime(now,c->loginTime);
    double hourUsed=secondUsed/3600.0;
    double cost = hourUsed*HOUR;
    if(c->balance>=cost){
        c->balance-=cost;
        cout<<"下机成功，使用时长："<<hourUsed<<"小时，费用："<<cost<<" 元\n";
        cout<<"剩余余额："<<c->balance<<" 元\n";
    }
    else{
        cout<<"余额不足，请充值\n";
    }
    c->isOnline=false;
    cm.saveToFile();
}
void Card::recharge(CardManager& cm){
    Card* c=cm.findCard();
    if(c==NULL){
        return;
    }
    cout<<"请输入想充值的金额：\n";
    double money;
    cin>>money;
    c->balance+=money;
    cm.saveToFile();
    return;
}
void Card::saveToFile(ofstream& ofs) const{
    ofs<<id<<' '<<password<<' '<<owner<<' '
       <<balance<<' '<<isOnline<<' '<<loginTime<<'\n';
}
Card Card::loadFromFile(ifstream& ifs){
    Card card;
    int onlineFlag;
    ifs>>card.id>>card.password>>card.owner>>card.balance>>onlineFlag>>card.loginTime;
    card.isOnline=(onlineFlag!=0);
    return card;
}




