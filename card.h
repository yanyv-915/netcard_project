#pragma once
#include<string>
#include<vector>
class Card{
public:
    std::string id;
    std::string password;
    std::string owner;
    double balance;
    bool isOnline;
    time_t loginTime;
    Card(std::string id_,std::string password_,std::string owner_);
    void recharge(double amount);
    void login();
    void logout();
    void show_use();
    friend std::ostream& operator<<(std::ostream& os,const Card& card);
};

class CardManager{
private:
    std::vector<Card>cards;
public:
    void addCard();
    std::vector<Card> findCard();
    bool deleteCard();
    void listCards();
};