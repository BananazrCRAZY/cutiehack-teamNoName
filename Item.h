#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <ctime>
using namespace std;

class Item {
    private:
        string _name;
        double _price;
        string _category;
        string _timestamp;

        void setTime();

    public:
        Item(string nameOfItem = "UNNAMED", int priceOfItem = -1, string categoryOfItem = "UNCATEGORIZED"); 

        // getters
        string getName() const;
        double getPrice() const;
        string getCategory() const;
        string getTime() const;

        // setters
        void setName(string nameOfItem);
        void setPrice(int priceOfItem);
        void setCategory(string categoryOfItem);
};

#endif