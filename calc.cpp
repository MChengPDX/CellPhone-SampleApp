/*
 * Michael Cheng
 * CS 202 Program 3
 * Winter 2016
 *
 * calc.cpp
 *
 * Provides class implementation for calculator prototypes
 * in calc.h.
 */


#include"calc.h"
#include<iostream>
using namespace std;

//Class Data Implementation

//Constructor for class data
Data::Data()
{
    value = 0;
}

//Assignment constructor
Data::Data(int v)
{
    value = v;

}

//overloading the + operator to perform addtion
Data Data::operator+(const Data & d) const
{
    Data result = *this;
    result.value =result.value + d.value;
    return result;
}

//overloading the - operator to perform subtraction
Data Data::operator-(const Data & d) const
{
    Data result = *this;
    result.value = result.value - d.value;
    return result;
}

//overloading the * operator to perform mutiplication
Data Data::operator*(const Data & d) const
{
    Data result = *this;
    result.value = result.value * d.value;
    return result;
}

//overloading the / to do division 
Data Data::operator/(const Data & d) const
{
    Data result = *this;
    result.value = result.value / d.value;
    return result;
}

void Data::display()
{
    cout << value;

}
