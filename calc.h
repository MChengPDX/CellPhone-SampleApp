/*
 * Michael Cheng
 * CS 202 Program 3
 * Winter 2016
 *
 * calc.h
 *
 * Provide class prototype for calculator applications
 * Supports simple add, subtract, mutiply and divide 
 * through operator overloading..
 * 
 */


//class data
class Data
{
    private:
        int value;
    public:
        Data();
        Data(int v);
        Data operator+(const Data & d) const;
        Data operator-(const Data & d) const;
        Data operator*(const Data & d) const;
        Data operator/(const Data & d) const;
        void display();
        
};
