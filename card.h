#pragma once
#include<string>
#include<vector>
#include<fstream>
#define HOUR 5.0
class CardManager;
class Card{
public:
    std::string id;
    std::string password;
    std::string owner;
    double balance;
    bool isOnline;
    time_t loginTime;
    Card(std::string id_,std::string password_,std::string owner_);
    Card()=default;
    void recharge(CardManager& cm);
    void login(CardManager& cm);
    void logout(CardManager& cm);
    void saveToFile(std::ofstream& ofs) const;
    static Card loadFromFile(std::ifstream& ifs);
    friend std::ostream& operator<<(std::ostream& os,const Card& card);
};

class CardManager{
public:
    std::vector<Card> cards;
    void addCard();
    Card* findCard();
    void deleteCard();
    void saveToFile(const std::string& fileneme="cards.txt");
    void loadFromFile(const std::string& fileneme="cards.txt");
};