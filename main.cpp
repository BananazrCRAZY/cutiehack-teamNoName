#include <iostream>
#include <vector>
#include "userInfo.h"
#include "Item.h"
#include "menu.h"
using namespace std;

int main(){
    string name;
    double income = 0;
    double percent = 0;
    bool running = true;

    cout << "Please Input Your Name: ";
    cin >> name;
    cout << endl;

    cout << "Please Input Your Income: ";
    cin >> income;
    cout << endl;

    userInfo user = userInfo(income, name);
    Menu menu = Menu(user);

    menu.showMenu();

    return 0;
    }   
