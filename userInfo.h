#ifndef USERINFO_H
#define USERINFO_H

#include <iostream>
#include "stdlib.h"
#include "Category.h"
#include <vector>
using namespace std;

class userInfo {
    private:
        double _income;
        string _name;
        vector<Category> v; 
        double totPercent;
    public:
        userInfo(double income = 0, string name = "noName");
        void setIncome(double income);
        void setName(string name);
        string getName();
        double getIncome();
        void addCategory(string nameOfCategory, double percentBudget);
        void printBudgets();
        void printIndexs();
        void setPercent(double per, unsigned index);
};

#endif