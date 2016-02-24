#include "text.h"
#include "ui.h"
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    Hashtable o;
    char m[] = "hello";
    String A;
    A = "ASDFSFSFAF";
    o.insert(m, A);
    o.find_one(m);
    o.display_all();
    /*
    bool done = false;
    ui interface;
    while(!done)
    {
        char option;
        cout <<"Choose an application : " << endl;
        cout <<"A. Calculator " << endl;
        cout <<"B. Maze Game " << endl;
        cout <<"C. View Text Messages " << endl;
        cin >> option;
        switch (toupper(option))
        {
            case 'A':
                interface.Calc_App();
                break;
            case 'B':
                break;
            case 'C':
                break;
            case 'D':
                cout << "Application closing. Goodbye " << endl;
                done = true;
                break;
            default:
                cout << "Not a valid option, pick again." << endl;
        }
    }
    */

}
