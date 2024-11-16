#include "Item.h"

Item::Item(string nameOfItem, int priceOfItem, string categoryOfItem) : _name(nameOfItem), _price(priceOfItem), _category(categoryOfItem) {}

// getters
string Item::getName() const {
    return this->_name;
}

double Item::getPrice() const {
    return this->_price;
}

string Item::getCategory() const {
    return this->_category;
}

// setters
void Item::setName(string nameOfItem) {
    this->_name = nameOfItem;
}

void Item::setPrice(int priceOfItem) {
    this->_price = priceOfItem;
}

void Item::setCategory(string categoryOfItem) {
    this->_category = categoryOfItem;
}