#include"card.h"
#include<iostream>
#include<cctype>
#include<string>
#include<windows.h>
using namespace std;
bool isValidNumber(std::string &s){
    for(char c:s){
        if(s.empty()) return false;
        if(!isdigit(c)) return false;
    }
    return true;
}
int main(){
    cout<<"欢迎使用网卡计费管理系统！\n";
    CardManager cm;
    Card c;
    while(true)
    {
        cout << "1.添加卡\n";
        cout << "2.查找卡\n";
        cout << "3.上机\n";
        cout << "4.下机\n";
        cout << "5.充值\n";
        cout << "6.注销卡\n";
        cout << "0.退出\n";
        cout << "请输入您的选择：\n";
        string input;
        cin >> input;
        if(!isValidNumber(input)){
            cout<<"请输入纯数字！";
            Sleep(1000);
            system("cls");
            continue;
        }
        int op=stoi(input);
        if(op>7||op<0){
            cout<<"输入有误，请重新输入！";
            Sleep(1000);
            system("cls");
            continue;
        }
        switch (op){
        case 1:
            cm.addCard();
            system("pause");
            system("cls");
            break;
        case 2:
        {
            Card *target = cm.findCard();
            
            if(target!= nullptr)
            {
                cout << "查找成功！\n";
                cout << *target;
            }
            system("pause");
            system("cls");
            break;
        }
        case 3:
            c.login(cm);
            system("pause");
            system("cls");
            break;
        case 4:
            c.logout(cm);
            system("pause");
            system("cls");
            break;
        case 5:
            c.recharge(cm);
            system("pause");
            system("cls");
            break;
        case 6:
            cm.deleteCard();
            system("pause");
            system("cls");
            break;
        case 0:
            system("pause");
            system("cls");
            return 0;
        }
    }
    cin.get();
    return 0;
}
