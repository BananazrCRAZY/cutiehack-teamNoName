#include <iostream>
#include "menu.h"
#include <string>
#include "userInfo.h"

using namespace std;

Menu::Menu(userInfo* menuOption){
    user = menuOption;
}

void Menu::showMenu(){
    int userInput;
    bool running = true;

    cout << "HELLO " << user->getName() << endl;

    while (running) {
        userInput = 0;
        cout << "PRESS ONE OF THE FOLLOWING NUMBERS" << endl;
        cout << "1: Show Budget" << endl;
        cout << "2: Set Budget" << endl;
        cout << "3: Show Expenses" << endl;
        cout << "4: Add Expense" << endl;
        cout << "5: Quit" << endl;

        cin >> userInput;
        cout << endl;

        if(userInput == 1){
            
        } else if(userInput == 2){
            
        } else if(userInput == 3){
            
        } else if(userInput == 4){
            
        } else if(userInput == 5){
            running = false;
        } else {
            cout << "Invalid Input" << endl;
        }
    }
}

void Menu::showBudget();
void Menu::setBudget();
void Menu::showExpenses();
void Menu::addExpense();