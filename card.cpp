#include"card.h"
#include"assit.h"
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;
Card::Card(string id_,string password_,string owner_){
    this->id=id_;
    this->owner=owner_;
    this->password=password_;
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
}
vector<Card> CardManager::findCard(){
    cout<<"请输入查找卡的持有者或者账号：\n";
    cout<<"1:按账号查询  "<<"2.按持有者查询"<<endl;
    int op;
    cin>>op;
    vector<Card>target;
    if(op==1){
        string owner;
        cout<<"请输入持有者姓名：\n";
        cin>>owner;
        for(auto c:cards){
            if(c.owner==owner) target.emplace_back(c);
        }
    }
    else{
        string id;
        cout<<"请输入卡的账号：\n";
        cin>>id;
        for(auto c:cards){
            if(c.id==id) {
                target.emplace_back(c);
                break;
            }
        }
    }
    return target;
}
