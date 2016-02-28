/*
 * Michael Cheng
 * CS 202 Program 3
 * Winter 2016
 *
 * main.cpp
 *
 * Provides an entrance to the program. Within this main, it wil
 * ask the user what application he/she would like to use.
 *
 * This program provides a simple stiumlation of what a basic cellphone 
 * application in the stone age would look like/do.
 *
 * Calculator application using operator overloading
 * texting messaging application stored through a hash table with channing
 * maze game through a self balancing tree with 3 pointers, one going left, right and back.
 * 
 */


#include "ui.h"
#include<iostream>
#include<cstring>
using namespace std;


int main()
{
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
                interface.Maze_App();
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
}

