// Name: ALP EREN KUL
// Student ID: 22244710073


#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList<FoodItem> appetizers, mainCourse, desserts;

    ifstream menuFile("menu.txt");

    if (!menuFile) {
        cerr << "Error: Could not open CMPE226.txt. Please make sure the file is in the correct directory." << endl;
        return 1;
    }

    string category, name;
    double price;
    int available;

    while (menuFile >> category >> name >> price >> available) {
        FoodItem item(name, price, available == 1);

        if (category == "Appetizers")
            appetizers.addItem(item);
        else if (category == "MainCourse")
            mainCourse.addItem(item);
        else if (category == "Desserts")
            desserts.addItem(item);
    }

    menuFile.close();

    cout << "Category: Appetizers";
    appetizers.displayInline();

    cout << "Category: Main Course";
    mainCourse.displayInline();

    cout << "Category: Desserts";
    desserts.displayInline();

    return 0;
}
