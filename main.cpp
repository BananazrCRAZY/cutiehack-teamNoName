#include <iostream>
#include <vector>
#include "userInfo.h"
#include "Item.h"
using namespace std;

int main(){
    string name;
    double income = 0;
    double percent = 0;
    bool running = true;

    cout << "Please Input Your Name: ";
    cin >> name;
    cout << endl;

    cout << "Please Input Your Income: ";
    cin >> income;
    cout << endl;

    cout << "Please Input The Percent You Would like To Budget: ";
    cin >> percent;
    cout << endl;

    userInfo *user = new userInfo(income, name);

    while (running) {

        bool answered = false;
        while (!answered) {
            
            }
        }

    
    }



    return 0;   
}
