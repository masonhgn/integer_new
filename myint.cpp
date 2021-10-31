#include <iostream>
#include "myint.h"

using namespace std;

int C2I(char c)
// converts character into integer (returns -1 for error)
{
    if (c < '0' || c > '9')	return -1;	// error
    return (c - '0');				// success
}

char I2C(int x)
// converts single digit integer into character (returns '\0' for error)
{
    if (x < 0 || x > 9)		return '\0';	// error
    return (static_cast<char>(x) + '0'); 	// success
}

// Add in operator overload and member function definitions
