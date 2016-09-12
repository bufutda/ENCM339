// ENCM 339 - Lab 9 - Exercise A and C - Fall 2015
// Lab9_List.cpp

#include <iostream>
#include <stdlib.h>
#include "lab9_List.h"

using std::cout;
using std::endl;

Lab9List::Lab9List(): headM(0) {

}

Lab9List::Lab9List(const Lab9List& source): headM(0) {
    copy(source);
}

Lab9List::Lab9List(const ListItem* arr, int n): headM(0) {
    for(int i = n-1; i >= 0; i--) {
        push_front(arr[i]);

    }

    // Point two - When program reaches this point for the first time
    // Please notice this point is after completion of for-loop
}

Lab9List::~Lab9List() {
    destroy();
}

Lab9List& Lab9List::operator =(const Lab9List& rhs) {
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }

    return *this;
}


void Lab9List::push_front(const ListItem& item) {
    Node *new_node = new Node;
    new_node->itemM = item;
    new_node->nextM = headM;
    headM = new_node;

    // point one: When program reaches this point for the first time.
}


void Lab9List::print() {
    if(headM == 0){
        cout << "\nlist is empty...\n";
        return;
    }

    Node* p = headM;
    while(p != 0) {
        cout << p->itemM << "  ";
        p = p -> nextM;
    }

    cout << endl;
}


void Lab9List::remove_1st(const ListItem& theItem) {
    if (headM == 0)
        return;
    Node* p = headM;
    Node* prev = headM;
    while (p->itemM != theItem && p->nextM) {
        prev = p;
        p = p->nextM;
    }
    if (p->itemM == theItem) {
        (p == headM ? headM : prev->nextM) = p->nextM;
        delete p;
    }
}


void Lab9List::copy(const Lab9List& source) {
    destroy();
    if (source.headM) {
        Node* index = source.headM;
        headM = new Node;
        Node* p = headM;
        do {
            p->itemM = index->itemM;
            p->nextM = (index->nextM ? new Node : 0);
            p = p->nextM;
            index = index->nextM;
        } while (index);
    }
}



void Lab9List::destroy() {
    if (headM) {
        Node* index = headM;
        while (index->nextM) {
            Node* ind = index->nextM;
            delete index;
            index = ind;
        }
        headM = 0;
    }
}
