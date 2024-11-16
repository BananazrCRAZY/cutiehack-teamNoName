#include <iostream>
#include "stdlib.h"
using namespace std;

class userInfo {
    private:
        double _income;
        string _name;
    public:
        userInfo(double income = 0, string name = "noName");
};