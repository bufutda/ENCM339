// ENCM 339 - Lab 9 - Exercise A and C - Fall 2015
// lab9_List.h

#ifndef Lab9_List_F15
#define Lab9_List_F15

typedef int ListItem;

class Lab9List {
    
private:
    
    struct Node {
        
        ListItem itemM;
        Node *nextM;
    };
    
    Node *headM;  // A pointer to the beginning of the list -- or a null pointer
                  // if list is empty.
    
    // HELPER FUNCTIONS
    void destroy();
    void copy(const Lab9List& source);
    
public:
    
    Lab9List();
    // PROMISES:
    //    creates an empty list.
    
    Lab9List(const ListItem* arr, int n);
    // REQUIRES:
    //    n > 0, and arr pointing to an array of ListItems with n elements.
    // PROMISES:
    //    List with n nodes is created; first node item will be equal to arr[0],
    //    second will be equal to arr[1], and so on..
    
    Lab9List(const Lab9List& source);
    
    Lab9List& operator =(const Lab9List& rhs);
    
    ~Lab9List();
    
    void push_front(const ListItem& item);
    // PROMISES:
    //    Adds a node with the value of item to the beginning of the list.
    
    void remove_1st(const ListItem& theItem);
    //  PROMISES:
    //     Searches for the first node in the list that its data value matches
    //     the value of theItem:
    //     - if such a node is found, it will be removed from the list, and its
    //       memory space will be deallocated from heap.
    //     - Otherwise, it will do nothing.
    
    void print();
    //  PROMISES:
    //     if list is not empty displays the existing values in the list.
    //     Otherwise, displays the message: "list is empty..."
};

#endif
