
#include"node.h"

#include "ui.h"
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    Maze m;
    m.insert(5);
    m.insert(2);
    m.insert(4);
    m.insert(5);
    m.insert(5);
    m.insert(4);
    m.insert(3);
    //m.display_all();
    //m.test();
    m.checkOrders();
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
        cout <<"D. Exit " << endl;
        cin >> option;
        switch (toupper(option))
        {
            case 'A':
                interface.Calc_App();
                break;
            case 'B':
                break;
            case 'C':
                interface.Text_App();
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
