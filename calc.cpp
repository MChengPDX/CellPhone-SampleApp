#include"calc.h"
#include<iostream>
using namespace std;

Data::Data()
{
    value = 0;
}
Data::Data(int v)
{
    value = v;

}

Data Data::operator+(const Data & d) const
{
    Data result = *this;
    result.value =result.value + d.value;
    return result;
}

Data Data::operator-(const Data & d) const
{
    Data result = *this;
    result.value = result.value - d.value;
    return result;
}


Data Data::operator*(const Data & d) const
{
    Data result = *this;
    result.value = result.value * d.value;
    return result;
}


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
