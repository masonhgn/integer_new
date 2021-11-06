// starter file for MyInt class header
#include <iostream>
using namespace std;
class MyInt
{
    // these overload starters are declared as friend functions

    friend MyInt operator+ (const MyInt& x, const MyInt& y);
    friend MyInt operator* (const MyInt& x, const MyInt& y);
    friend MyInt operator++ (const MyInt& x);

    friend ostream& operator<<(ostream&, const MyInt&);
    friend istream& operator>>(istream&, const MyInt&);

    friend bool operator< (const MyInt& x, const MyInt& y);
    friend bool operator> (const MyInt& x, const MyInt& y);
    friend bool operator<= (const MyInt& x, const MyInt& y);
    friend bool operator>= (const MyInt& x, const MyInt& y);
    friend bool operator!= (const MyInt& x, const MyInt& y);
    friend bool operator== (const MyInt& x, const MyInt& y);


    // add in the other comparison overloads, as well

    // declare overloads for input and output (MUST be non-member functions)
    //  you may make them friends of the class

public:
    MyInt(int n=0);		// first constructor int input
    MyInt(const char* c);//c style string
    ~MyInt(); //destructor
    MyInt(const MyInt& ); //copy constructor
    MyInt & operator= (const MyInt &); //assignment operator
    void lengthInt(int n);
    int C2I(char c);
    char I2C(int x);
    void ConvInt(int n);
    void SetDefault();
    void Grow();
    void Resize();


    // be sure to add in the second constructor, and the user-defined
    //  versions of destructor, copy constructor, and assignment operator

private:
    int* ints;
    int current_size;
    int max_size;

    // member data (suggested:  use a dynamic array to store the digits)

};
