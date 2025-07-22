#include"card.h"
#include"assit.h"
#include<iostream>

using namespace std;
int main(){
    cout<<"欢迎使用网卡计费管理系统！\n";
    CardManager cm;
    while(true)
    {
        cout << "1.添加卡\n";
        cout << "2.查找卡\n";
        cout << "3.上机\n";
        cout << "4.下机\n";
        cout << "5.充值\n";
        cout << "6.注销卡\n";
        cout << "7.查找当前卡过去使用情况\n";
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
            for(auto c:cm.findCard()){
                cout<<c<<"\n";
            }
            system("pause");
            system("cls");

            break;
        case 3:
            system("pause");
            system("cls");
            break;
        case 4:
            system("pause");
            system("cls");
            break;
        case 5:
            system("pause");
            system("cls");
            break;
        case 6:
            system("pause");
            system("cls");
            break;
        case 7:
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
