#include <iostream>
#include <stdlib.h>
#include "menu.h"
#include <string>
#include "userInfo.h"
#include <fstream>

using namespace std;


Menu::Menu(userInfo menuOption){
    user = menuOption;
}

void Menu::showMenu() {
    int userInput;
    bool running = true;

    cout << "Hello " << user.getName() << "!" << endl;

    askInitialCategories();

    while (running) {
        userInput = 0;
        cout << "Choose one of the following options (1-6): " << endl;
        cout << "1: Show Budget" << endl;
        cout << "2: Set Budget" << endl;
        cout << "3: Show Expenses" << endl;
        cout << "4: Add Expense" << endl;
        cout << "5: Export Expenses" << endl;
        cout << "6: Quit" << endl;

        cin >> userInput;
        cout << endl;

        if(userInput == 1){
            system("clear");
            showBudget();
        } else if(userInput == 2){
            system("clear");
            setBudget();
        } else if(userInput == 3){
            system("clear");
            showExpenses();
        } else if(userInput == 4){
            system("clear");
            addExpense();
        } else if (userInput == 5) {
            system("clear");
            string userFile = "";
            cout << "Enter name of file to export to. File will be exported in a json format." << endl;
            cin >> userFile;
            exportExpenses(user, userFile);
        } else if(userInput == 6){
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
        system("clear");
        cout << "Input new Income: ";
        double newIncome = 0;
        cin >> newIncome;
        cout << endl;
        user.setIncome(newIncome);
    } else if (answer == 2) {
        system("clear");
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
    system("clear");
    user.printIndexs();
    cout << "Input a number for the Category you wish to see: ";
    unsigned index = 0;
    cin >> index;
    cout << endl;
    cout << user.v.at(index) << endl;
}

void Menu::addExpense() {
    system("clear");
    cout << "PRESS ONE OF THE FOLLOWING NUMBERS" << endl;
    cout << "1: Create a Category" << endl;
    cout << "2: Add an item" << endl;

    int answer = 0;
    cin >> answer;

    if (answer == 1) {
        system("clear");
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
        system("clear");
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
        string itemCat = user.v.at(index).getCategoryName();
        Item it = Item(itemName, cost, itemCat);
        user.v.at(index).add(it);
    }
}

void Menu::askInitialCategories() {
    cout << "Before we start, please input the following categories you'd like to budget for, followed by a new line (e.g. Travel)" << endl;
    cout << "To stop, press q." << endl;

    string userCategory = "";
    cin >> userCategory;

    while (userCategory != "q") {
        user.addCategory(userCategory, -1);
        cin >> userCategory;
    }

    system("clear");

    cout << "Great! Now please set percentages to indicate the percentage of your income to allocate to your budget." << endl;

    double userPercentage = 0;
    for (unsigned i = 0; i < user.v.size(); i++) {
        cout << user.v.at(i).getCategoryName() << ": ";
        cin >> userPercentage;
        user.v.at(i).setPercentBudget(userPercentage);
        cout << endl;
    } 
    

    system("clear");
    cout << "Your budgeting categories are: " << endl;
    for (unsigned i = 0; i < user.v.size(); i++) {
        cout << user.v.at(i).getCategoryName() << ": " << user.v.at(i).getPercentBudget() << "%" << endl;
    }
    cout << endl;
}

void Menu::exportExpenses(userInfo &user, string nameOfFile) {
    ofstream outFS;
    outFS.open(nameOfFile);
    if (!outFS.is_open()) {
      cout << "Could not open " << nameOfFile << endl;
    } else {
        for (unsigned i = 0; i < user.v.size(); i++) {
            for (unsigned j = 0; j < user.v.at(i)._items.size(); j++) {
                outFS << "{\"datetime\": \"" << user.v.at(i)._items.at(j).getTime() << "\", ";
                outFS << "\"product_name\": \"" << user.v.at(i)._items.at(j).getName() << "\", ";
                outFS << "\"category\": \"" << user.v.at(i)._items.at(j).getCategory() << "\", ";
                outFS << "\"price\": \"" << user.v.at(i)._items.at(j).getPrice() << "\"}, " << endl;

            }
        }
    }

    cout << "Expenses successfully exported to " << nameOfFile << "." << endl;
}
