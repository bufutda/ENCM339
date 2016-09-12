// lab7_ExA.cpp
// ENCM 339 Fall 2015 Lab 7 Exercise A

#include <iostream>
using namespace std;

void moon(int& arg1, int* arg2);

void mars(const int& arg1, int*& arg2);

void jupiter(int& x);

int main()
{
    int arr[] = { 1500, 1100, 1600 };
    int& ref = arr[2];

    moon(ref, arr);
    ref++;

    int* p = &arr[0];

    mars(arr[1] + 300, p);
    cout << arr[0] << " " << arr[1] << "  "<< arr[2] << "  " << ref  <<endl;

    return 0;
}

void moon(int& arg1, int* arg2)
{
    arg1++;
    (*arg2)++;

    // point one

    return;
}

void mars(const int& arg1, int*& arg2)
{
    *arg2 = arg1 + 200;

    jupiter(*arg2);

    return;
}


void jupiter(int& x)
{
    x += 100;

    // point two

    return;
}
