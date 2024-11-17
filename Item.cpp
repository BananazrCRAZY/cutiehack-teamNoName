#include "Item.h"

Item::Item(string nameOfItem, int priceOfItem, string categoryOfItem) : _name(nameOfItem), _price(priceOfItem), _category(categoryOfItem) {
    setTime();
}

void Item::setTime() {
    time_t currTime = time(0);
    tm *localTime = localtime(&currTime);

    int year = localTime->tm_year + 1900;
    int month = localTime->tm_mon + 1;
    int day = localTime->tm_mday;

    int hr = localTime->tm_hour;
    int min = localTime->tm_min;
    int sec = localTime->tm_sec;

    std::string formattedTime = 
                        std::to_string(month) + "/" + 
                        std::to_string(day) + "/" + 
                        std::to_string(year) + " " + 
                        std::to_string(hr) + ":" + 
                        std::to_string(min) + ":" + 
                        std::to_string(sec);

    this->_timestamp = formattedTime;
}

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

string Item::getTime() const {
    return this->_timestamp;
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