#include "userInfo.h"

userInfo::userInfo(double income, string name) : _income(income), _name(name) {}

void userInfo::setIncome(double income) {
    _income = income;
}

void userInfo::setName(string name) {
    _name = name;
}

string userInfo::getName(){
    return _name;
}

double userInfo::getIncome(){
    return _income;
}