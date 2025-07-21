#pragma
#include<string>
#include<vector>
class Card{
public:
    std::string id;
    std::string owner;
    double balance;
    bool isOnline;
    time_t loginTime;
    Card(std::string id_,std::string owner_);
    void recharge(double amount);
    double logout();
};

class CardManager{
private:
    std::vector<Card>cards;
public:
    void addCard(const std::string& id,const std::string& name);
    Card* findCard(const std::string& id);
    bool deleteCard(const std::string& id);
    void listCards();
};