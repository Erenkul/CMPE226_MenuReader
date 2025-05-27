// Name: ALP EREN KUL
// Student ID: 22244710073


#pragma once
#include <iostream>
#include <string>
using namespace std;

struct FoodItem {
    string name;
    double price;
    bool available;

    FoodItem(string n = "", double p = 0.0, bool a = false) {
        name = n;
        price = p;
        available = a;
    }

    friend ostream& operator<<(ostream& os, const FoodItem& item) {
        os << item.name << " ($" << item.price << ") ["
            << (item.available ? "Available" : "Not Available") << "]";
        return os;
    }
};

template<class T>
struct Node {
    T info;
    Node* link;

    Node(T data) {
        info = data;
        link = NULL;
    }
};

template<class T>
class LinkedList {
public:
    Node<T>* head;
    Node<T>* last;

    LinkedList() {
        head = NULL;
        last = NULL;
    }

    void addItem(T data) {
        Node<T>* p = new Node<T>(data);
        if (head == NULL) {
            head = p;
            last = p;
        }
        else {
            last->link = p;
            last = p;
        }
    }

    void displayInline() {
        Node<T>* current = head;
        while (current != NULL) {
            cout << " - " << current->info;
            current = current->link;
        }
        cout << endl;
    }
};

