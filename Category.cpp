#include "Category.h"

Category::Category(string nameOfCategory, double total, double percentBudget, double userIncome) : _categoryName(nameOfCategory), _total(total), _percentBudget(percentBudget), _userIncome(userIncome), _remaining((_userIncome*_percentBudget)/100){}

// getters
string Category::getCategoryName() const {
    return this->_categoryName;
}
double Category::getTotal() const {
    return this->_total;
}
double Category::getPercentBudget() const {
    return this->_percentBudget;
}
double Category::getRemaining() const {
    return this->_remaining;
}

// setters
void Category::setCategoryName(string nameOfCategory) {
    this->_categoryName = nameOfCategory;
}
void Category::setTotal(double totalAmount) {
    this->_total = totalAmount;
}
void Category::setPercentBudget(double percentOfBudget) {
    this->_percentBudget = percentOfBudget;
    _remaining = (_userIncome * _percentBudget) / 100;
}

void Category::setUserIncome(double newUserIncome) {
    _userIncome = newUserIncome;
    _remaining = (_userIncome * _percentBudget) / 100;
}


// mutators

/*
    Adds an Item to the back of the vector of Items. Calls push_back() from the vector class
*/
void Category::add(Item &item) {
    this->_items.push_back(item);
    this->_remaining -= item.getPrice();
}

/*
    Removes the most recently added Item from the vector of Items. Calls pop_back() from the vector class
*/
void Category::remove_back() {
    this->_items.pop_back();
}

ostream & operator<<(ostream &o, const Category &rhs) {

    for (unsigned i = 0; i < rhs._items.size(); i++) {
        o << rhs.getCategoryName() << ": " << endl;
        o << rhs._items.at(i).getName() << ": $" << rhs._items.at(i).getPrice() << endl;
    }

    return o;
}