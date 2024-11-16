#ifndef MENU_H
#define MENU_H

#include "userInfo.h"

class Menu{
    private:
    int userInput;
    userInfo *user;

    public:
    void showMenu();
};

#endif