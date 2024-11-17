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
            showBudget();
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

void Menu::showBudget() {
    user->printBudgets();
}

void Menu::setBudget() {
    cout << "PRESS ONE OF THE FOLLOWING NUMBERS" << endl;
    cout << "1: Change/Set Income" << endl;
    cout << "2: Change/Set Budget %" << endl;

    int answer = 0;
    cin >> answer;

    if (answer == 1) {
        cout << "Input new Income: ";
        double newIncome = 0;
        cin >> newIncome;
        user->setIncome(newIncome);
    } else if (answer == 2) {
        user->printIndexs();
        cout << "Input a number for the Category you wish to edit: ";
        unsigned index = 0;
        cin >> index;
        cout << "Input a new budget %: ";
        double percent = 0;
        cin >> percent;
        user->setPercent(percent, index);
    }
}

void Menu::showExpenses() {
    user->printIndexs();
    
}

void Menu::addExpense() {

}