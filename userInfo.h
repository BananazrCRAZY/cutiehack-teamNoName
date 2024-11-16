#ifndef USERINFO_H
#define USERINFO_H

#include <iostream>
#include "stdlib.h"
using namespace std;

class userInfo {
    private:
        double _income;
        string _name;
    public:
        userInfo(double income = 0, string name = "noName");
        setIncome(double income);
        setName(string name);
};

#endif