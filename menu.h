#ifndef MENU_H
#define MENU_H

#include "userInfo.h"

class Menu{
    private:
    int userInput;
    userInfo user;

    public:
        void showMenu();
        void askInitialCategories();
        Menu(userInfo menuOption);
        void showBudget();
        void setBudget();
        void showExpenses();
        void addExpense();
        void exportExpenses(userInfo &user, string nameOfFile);
};

#endif