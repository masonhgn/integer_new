// starter file for MyInt class header


class MyInt
{
    // these overload starters are declared as friend functions

    friend MyInt operator+ (const MyInt& x, const MyInt& y);
    friend MyInt operator* (const MyInt& x, const MyInt& y);

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
    MyInt(int n = 0);		// first constructor
    MyInt(char n[] = "");//c style string
    // be sure to add in the second constructor, and the user-defined
    //  versions of destructor, copy constructor, and assignment operator

private:

    // member data (suggested:  use a dynamic array to store the digits)

};