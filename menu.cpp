#include <iostream>
#include "menu.h"
#include <string>
#include "userInfo.h"

using namespace std;

void Menu::showMenu(){
    int userInput;

    cout << "HELLO " << user->getName() << endl;

    cout << "PRESS ONE OF THE FOLLOWING NUMBERS" << endl;
    cout << "1: Show Budget" << endl;
    cout << "2: Set Budget" << endl;
    cout << "3: Show Expenses" << endl;
    cout << "4: Add Expense" << endl;
    cout << "5: Quit" << endl;
}
