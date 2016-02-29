/*
 * Michael Cheng
 * CS 202 Program 3
 * Winter 2016
 *
 * ui.cpp
 * Calls on function within calc.cpp, text.cpp and maze.cpp. Acts like a manger
 * or glue class and binds all these parts together into one working application
 */

#include "ui.h"

//mazing application interface
void ui::Maze_App()
{
    //Bulding the Maze
    Maze b;
    b.insert(5);
    b.insert(4);
    b.insert(6);
    b.insert(3);
    b.insert(2);
    b.insert(8);
    b.insert(9);
    b.insert(6);
    b.insert(2);
    b.insert(100);
    b.set_previous();
    //Options
    bool done = false;
    char option; 
    while(!done)
    {
        cout << "HINT if you go all the way right, you win the game " << endl;
        cout << "A. Play the game." << endl;
        cout << "B. Exit." << endl;
        cout << "Testing Functions." << endl;
        cout << "C. Display All. " << endl;
        cout << "D. Remove All. " << endl;
        cin.ignore();
        option = cin.get();
        cin.clear();
        switch(toupper(option))
        {
            case'A':
                b.move();
                done = true;
                break;
            case'B':
                done = true;
                break;
            case'C':
                b.display_all();
                break;
            case'D':
                b.remove_all();
                cout <<"Tree has been deleted, now exiting out of appplication";
                cout << endl;
                done = true;
                break;
            default:
                cout << "Not valid option." << endl;
                break;
        }
    }
}


//texting application interface
void ui::Text_App()
{
    char name1 [] = "Michael";
    char name2 [] = "Karla";
    char name3 [] = "Random Person";
    String test1;
    String test2;
    String test3;
    String test4;
    test1 = "Test string 1";
    test2 = "Test string 2";
    test3 = "Test string 3";
    test4 = "Test string 4";

    Hashtable o;
    o.insert(name1, test1);
    o.insert(name1, test2);
    o.insert(name2, test1);
    o.insert(name2, test3);
    o.insert(name2, test4);
    o.insert(name3, test1);
    o.insert(name3, test4);
    char option;
    bool done = false;
    while(!done)
    {
        cout << "Text Messaging Application" << endl;
        cout << "A. Display all text." << endl;
        cout << "B. Find a sender." << endl;
        cout << "C. Remove all text. " << endl;
        cout << "D. Exit " << endl;
        cin.ignore();
        option = cin.get();
        switch(toupper(option))
        {
            case 'A':
                o.display_all();
                break;
            case 'B':
                char tofind[100];
                cout << "Type a name to find : " << endl;
                cin.get(tofind, 100, '\n');
                cin.ignore(100, '\n');
                o.find_one(tofind);
                break;
            case 'C':
                o.remove_all();
                break;
            case 'D':
                cout <<"Exiting text application. " << endl;
                done = true;
                break;
            default:
                cout << "Invalid option, try again. " << endl;
        }
    }
}


//Calculator application interface
void ui::Calc_App()
{
    char option;
    bool done = false;

    //switch statement to perform what operator to do
    while(!done)
    {
        int value1 = 0;
        int value2 = 0;
        cout << "Enter first value : " << endl;
        cin >> value1;
        cin.ignore(256, '\n');
        cin.clear();
        cout << "Enter second value : " << endl;
        cin >> value2;
        cin.ignore(256, '\n');
        cin.clear();
        Data result;
        Data d1(value1);
        Data d2(value2);
      //Prompt user for operation
        cout <<"Select the operation you want to do : " << endl;
        cout <<"A. Addition(+)" << endl;
        cout <<"B. Subtraction(-)" << endl;
        cout <<"C. Multiplication(x)" << endl;
      //  cout <<"D. Division(a/b)" << endl;
        cout <<"E. Exit " << endl;
        option = cin.get();
        cin.ignore(256, '\n');
        cout << endl;

        switch(toupper(option))
        {
            case 'A':
                result = d1+d2;
                cout << "The sum of " << value1 << " and " << value2 << " is ";
                result.display();
                cout << endl;
                value1 = 0;
                value2 = 0;
                break;
            case 'B':
                result = d1-d2;
                cout <<" The subtraction of " << value1 << " and " << value2 << " is ";
                result.display();
                cout << endl;
                value1 = 0;
                value2 = 0;
                break;
            case 'C':
                result =d1*d2;
                cout << "The mutiplicatiion of " << value1 << " and " << value2 << " is ";
                result.display();
                cout << endl;
                value1 = 0;
                value2 = 0;
                break;
                /*
            case 'D':

                break;
                */
            case 'E':
                cout <<"Exiting out of calculator application " << endl;
                done = true;
                break;
            default:
                cout <<"Invalid option, try again. " << endl;
                
        }

    }

}
