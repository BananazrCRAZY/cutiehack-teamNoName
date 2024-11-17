#include <iostream>
#include "menu.h"
#include <string>
#include "userInfo.h"

using namespace std;


Menu::Menu(userInfo menuOption){
    user = menuOption;
}

void Menu::showMenu() {
    int userInput;
    bool running = true;

    cout << "HELLO " << user.getName() << endl;

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
            setBudget();
        } else if(userInput == 3){
            showExpenses();
        } else if(userInput == 4){
            addExpense();
        } else if(userInput == 5){
            running = false;
        } else {
            cout << "Invalid Input" << endl;
        }
    }
}

void Menu::showBudget() {
    user.printBudgets();
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
        cout << endl;
        user.setIncome(newIncome);
    } else if (answer == 2) {
        user.printIndexs();
        cout << "Input a number for the Category you wish to edit: ";
        unsigned index = 0;
        cin >> index;
        cout << endl;
        cout << "Input a new budget %: ";
        double percent = 0;
        cin >> percent;
        cout << endl;
        user.setPercent(percent, index);
    }
}

void Menu::showExpenses() {
    user.printIndexs();
    cout << "Input a number for the Category you wish to see: ";
    unsigned index = 0;
    cin >> index;
    cout << endl;
    cout << user.v.at(index) << endl;
}

void Menu::addExpense() {
    cout << "PRESS ONE OF THE FOLLOWING NUMBERS" << endl;
    cout << "1: Create a Category" << endl;
    cout << "2: Add an item" << endl;

    int answer = 0;
    cin >> answer;

    if (answer == 1) {
        cout << "Enter the name of the Category: ";
        string name;
        cin >> name;
        cout << endl;
        cout << "Enter what % you would like to budget: ";
        double percent = 0;
        cin >> percent;
        cout << endl;
        user.addCategory(name, percent);
    } else if (answer == 2) {
        user.printIndexs();
        cout << "Input a number for the Category you wish to edit: ";
        unsigned index = 0;
        cin >> index;
        cout << endl;
        cout << "Enter the name of the item: ";
        string itemName;
        cin >> itemName;
        cout << endl;
        cout << "Enter the cost of the item: ";
        double cost = 0;
        cin >> cost;
        cout << endl;
        cout << "Enter item type: ";
        string type;
        cin >> type;
        cout << endl;
        Item it = Item(itemName, cost, type);
        user.v.at(index).addItem(it);
    }
}