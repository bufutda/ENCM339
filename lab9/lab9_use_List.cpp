// ENCM 339 - Lab 9 - Exercise A and C - Fall 2015
// lab9_use_List.cpp

#include <iostream>
#include <iomanip>
#include "lab9_List.h"

using std::cout;

#define SIZE 2

void test_removing(Lab9List& list);
// PROMISES:
//    checks if the written code for Lab9List::remove_1st works for a set of
//    test cases.

void test_copying(Lab9List& list);
// PROMISES:
//    checks if the written code for copy constructor and copy assignment
//    operator works for a set of test cases.

int main() {
    ListItem a[SIZE] = {300, 450};

    Lab9List list1;
    cout << "list1 - created:";
    list1.print();

    list1.push_front(50);
    cout << "\nlist1 - after a call to push_front:\n";
    list1.print();

    Lab9List list2(a, SIZE);
    cout << "\nlist2 - created:\n";
    list2.print();

    list2.push_front(550);
    list2.push_front(440);
    list2.push_front(330);
    list2.push_front(220);
    list2.push_front(300);

    cout << "\nlist2 - after several calls to push_front has: \n";

    list2.print();

#if 1
    test_removing(list2);
#endif

#if 1
    test_copying(list2);
#endif

    return 0;
}

void test_removing(Lab9List& list) {
    cout << "\n------------------ Function test_removing started ------------\n";
    cout << "\nlist: expected to have seven nodes:  300  220  330  440  550"
    << "  300  450\n";
    cout << "actual output:\n  ";
    list.print();

    list.remove_1st(220);
    list.remove_1st(550);
    cout << "\nAfter two removes - expected to display:  300  330  440  300  450\n";
    cout << "actual output:\n  ";
    list.print();

    list.remove_1st(300);
    cout << "\nAfter one more remove - expected to display:  330  440  300  450\n";
    cout << "actual output:\n  ";
    list.print();

    list.remove_1st(300);
    cout << "\nAfter another remove - expected to display:  330  440  450\n";
    cout << "actual output:\n  ";
    list.print();

    list.remove_1st(2000);
    cout << "\nLast remove - still expected to display:  330  440  450\n";
    cout << "actual output:\n  ";
    list.print();
}

void test_copying(Lab9List& list) {

    cout << "\n------------------ Function test_copying started --------------\n";
    cout << "\nAfter removing several nodes in test_removing, list must have: ";
    list.print();

    Lab9List list1 = list;

    cout << "\nlist1 - expected to display: "; list.print();
    cout << "actual output:\n  ";
    list1.print();

    list.remove_1st(330);
    cout << "\nlist - after removing 330 - expected to display:  440  450\n";
    cout << "actual output:\n  ";
    list.print();

    cout << "\nlist1 - still expected to dispay:  330  440  450\n";
    cout << "actual output:\n  ";
    list1.print();

    Lab9List list2;
    list2 = list1;
    cout << "\nlist2 - expected to display: "; list1.print();
    cout << "actual output:\n  ";
    list2.print();

    list1.push_front(989);
    cout << "\nlist1 - expected to display:  989  330  440  450\n";
    cout << "actual output:\n  ";
    list1.print();

    cout << "\nlist2 - still expected to display:  330  440  450\n";
    cout << "actual output:\n  ";
    list2.print();

    ListItem arr[3] = {1000, 2000, 1234};

    Lab9List list3(arr, 3);
    cout << "\nlist3 - expected to display:  1000  2000  1234\n";
    cout << "actual output:\n  ";
    list3.print();

    Lab9List list4;
    cout << "\nlist4 - expected to be empty.\n";
    cout << "actual output:  ";
    list4.print();
    list3 = list4;
    cout << "\nlist3 - is now expected to be empty. \n";
    cout << "actual output:  ";
    list3.print();
}
