#include "userInfo.h"

userInfo::userInfo(double income, string name) : _income(income), _name(name) {}

void userInfo::setIncome(double income) {
    _income = income;
    for (unsigned i = 0; i < v.size(); i++) {
        v.at(i).setUserIncome(income);
    }
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

void userInfo::addCategory(string nameOfCategory, double percentBudget) {
    Category c(nameOfCategory, 0, percentBudget, _income);
    v.push_back(c);
}

void userInfo::printBudgets() {
    for (unsigned i = 0; i < v.size(); i++) {
        cout << i << ": " << v.at(i).getCategoryName() << ": $" << v.at(i).getRemaining() << " remaining" << endl;
    }
}