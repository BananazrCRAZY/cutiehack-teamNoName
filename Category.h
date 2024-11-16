#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Category{
    private:
        string _categoryName;
        vector<Item> _items;
        double _total;
        double _percentBudget;
        double _userIncome;
        double _remaining;

    public:
        Category(string nameOfCategory = "NO_CATEGORY", double total = 0, double percentBudget = -1, double userIncome = -1);
        
        // getters
        string getCategoryName() const;
        double getTotal() const;
        double percentBudget() const;
        double getRemaining() const;

        // setters
        void setCategoryName(string nameOfCategory);
        void setTotal(double totalAmount);
        void setPercentBudget(double percentOfBudget);
        void setUserIncome(double newUserIncome);

        // mutators
        void add(Item &item);
        void remove_back();

        friend ostream & operator<<(ostream &o, const Category &rhs);
};


#endif