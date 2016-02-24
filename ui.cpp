#include"ui.h"

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
        cin.ignore();
        cout << "Enter second value : " << endl;
        cin >> value2;
        cin.ignore();
        Data result;
        Data d1(value1);
        Data d2(value2);
      //Prompt user for operation
        cout <<"Select the operation you want to do : " << endl;
        cout <<"A. Addition(+)" << endl;
        cout <<"B. Subtraction(-)" << endl;
        cout <<"C. Multiplication(x)" << endl;
        cout <<"D. Division(a/b)" << endl;
        cout <<"E. Exit " << endl;
        cin >> option;
        cin.ignore();
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
            case 'D':

                break;
            case 'E':
                cout <<"Exiting out of calculator application " << endl;
                done = true;
                break;
            default:
                cout <<"Invalid option, try again. " << endl;
                
        }

    }

}
