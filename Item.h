#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

class Item {
    private:
        string _name;
        double _price;
        string _category;

    public:
        Item(string nameOfItem = "UNNAMED", int priceOfItem = -1, string categoryOfItem = "UNCATEGORIZED"); 

        // getters
        string getName() const;
        double getPrice() const;
        string getCategory() const;

        // setters
        void setName(string nameOfItem);
        void setPrice(int priceOfItem);
        void setCategory(string categoryOfItem);
};

#endif