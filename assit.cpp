#include"assit.h"
bool isValidNumber(std::string &s){
    for(char c:s){
        if(s.empty()) return false;
        if(!isdigit(c)) return false;
    }
    return true;
}