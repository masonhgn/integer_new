#include <iostream>
#include "myint.h"
#include <cstring>
#include <math.h>
using namespace std;



MyInt::MyInt::MyInt(int n) {

    ints = NULL;
    if (n<=0) {
        SetDefault();
    } else {
        ConvInt(n);
    }

//cout << "constructor found";
}
MyInt::~MyInt() {
    delete[] ints;
}

MyInt::MyInt(const char *c) {
    int temp = 0;
    ints = NULL;
    current_size = strlen(c);
    max_size = current_size+2;
    ints = new int[current_size];
    for (int i=0;i<current_size;i++) {
        temp = C2I(c[i]);
        ints[i] = temp;
    }

}

MyInt::MyInt(const MyInt & d) {
    max_size = d.max_size;
    current_size = d.current_size;
    ints = new int[d.max_size];
}




int MyInt::C2I(char c)
// converts character into integer (returns -1 for error)
{
    if (c < '0' || c > '9')	return -1;	// error
    return (c - '0');				// success
}

char MyInt::I2C(int x)
// converts single digit integer into character (returns '\0' for error)
{
    if (x < 0 || x > 9)		return '\0';	// error
    return (static_cast<char>(x) + '0'); 	// success
}



// Add in operator overload and member function definitions
MyInt operator+(const MyInt &x, const MyInt &y) {
    MyInt temp;
    int sum = 0, carry = 0, hold = 0;
    bool flag = true;
        for (int i = x.current_size-1, j=y.current_size-1; (i>=0 || j >= 0); i--, j--) {
            int a = 0,b = 0;
            if (i>= 0) a=x.ints[i];
            if (j>=0) b=y.ints[j];
            sum = a + b + carry; //create sum using last carry value
            if (sum > 9) {
                carry = sum/10; //create new carry value
                hold = sum%10; //create new hold value
            }
            else carry = 0, hold = sum;

            if (temp.current_size==temp.max_size) temp.Grow();
            if (flag) {
                flag = false;
                temp.ints[0] = hold;
            } else temp.ints[temp.current_size++] = hold;
        }
        if (carry) { //if there is a carry value then p
            if (temp.current_size==temp.max_size) {
                temp.Grow();
            }
            temp.ints[temp.current_size++] = 1;
        }
    for (int i=0;i<temp.current_size/2;i++) { // reverse order of temp
        int temp2 = temp.ints[i];
        temp.ints[i] = temp.ints[temp.current_size-i-1];
        temp.ints[temp.current_size-i-1] = temp2;
    }
    return temp;
}


MyInt operator*(const MyInt &x, const MyInt &y) {
    MyInt temp, temp_final;
    int count = 0;
    int subproduct = 0;
    int hold = 0;
    for (int i=y.current_size-1;i>=0;--i) { //loop through all digits of second number
        cout << "         =digit "<< y.ints[i] << endl;
        int carry = 0;

        for (int a=x.current_size-1;a>=0;--a) {//loop through all digits of first number backwards
            cout << x.ints[a] << endl;
            subproduct = (y.ints[i] * x.ints[a]) + carry;
            if (subproduct > 9) {
                carry = subproduct/10;
                hold = subproduct%10;
            }
            else {
                hold = subproduct;
            }
            if (temp.current_size==temp.max_size) {
                temp.Grow();
            }
            cout << "                         hold = " << hold << endl;
            cout << "                         carry = " << carry << endl;
            temp.ints[count] = hold;
            cout << "count: " << count << endl;
            cout << "temp:  " << temp << endl;

            ++count;
            temp.current_size++;
        }

        cout << "TEMP: " << temp << endl;
        //temp = 0;
    }
    return temp_final;
}

bool operator<(const MyInt &x, const MyInt &y) {
    if (x.current_size < y.current_size) {
        return true;
    } else if (y.current_size < x.current_size) {
        return false;
    } else {
        for (int i=0;i<x.current_size;i++) {
            if (x.ints[i] < y.ints[i]) return true;
        }
    }
    return false;
}

bool operator>(const MyInt &x, const MyInt &y) {
    if (x.current_size > y.current_size) {
        return true;
    } else if (y.current_size > x.current_size) {
        return false;
    } else {
        for (int i=0;i<x.current_size;i++) {
            if (x.ints[i] > y.ints[i]) return true;
        }
    }
    return false;
}

bool operator<=(const MyInt &x, const MyInt &y) {
    if (x==y) return true;
    if (x.current_size < y.current_size) {
        return true;
    } else if (y.current_size < x.current_size) {
        return false;
    } else {
        for (int i=0;i<x.current_size;i++) {
            if (x.ints[i] < y.ints[i]) return true;
        }
    }
    return false;
}
bool operator>=(const MyInt &x, const MyInt &y) {
    if (x==y) return true;
    if (x.current_size > y.current_size) {
        return true;
    } else if (y.current_size > x.current_size) {
        return false;
    } else {
        for (int i=0;i<x.current_size;i++) {
            if (x.ints[i] > y.ints[i]) return true;
        }
    }
    return false;
}
bool operator!=(const MyInt &x, const MyInt &y) {
    if (!(x==y)) {
        return true;
    }
    return false;
}
bool operator==(const MyInt &x, const MyInt &y) {
    int count = 0;
    for (int i=0;i<x.current_size;i++) {
        if (x.ints[i] == y.ints[i]) {
            count++;
        }
    }
    if (count == x.current_size) {
        return true;
    }
    return false;
}
void MyInt::SetDefault() {
    if (ints != NULL) {
        delete[] ints;
    }
    current_size = 1;
    max_size = 3;
    ints = new int[max_size];
    ints[0] = 0;
}
void MyInt::ConvInt(int n) { //works!!!
    current_size = 0;
    max_size = 2;
    int x = n;
    while (x != 0) {
        x = x/10;
        current_size++;
    }
    max_size += current_size;

    ints = new int[max_size];
    x = n;
    for (int i=current_size-1;i>=0;i--) {
        ints[i] = x%10;
        x = x/10;
    }
}

ostream &operator<<(ostream &os, const MyInt &s) {

    for (int i=0;i<s.current_size;i++) {
        os << s.ints[i];
    }
    return os;
}
//////////////////////////////////////////////////
istream &operator>>(istream &is, MyInt &s) {
    char c = is.get();
    int count = 0;
    while (isdigit(c)) {
        int x = s.C2I(c);

        if (s.current_size == s.max_size) {
            s.Grow();
        }
        cout << x << endl;
        s.ints[count] = x;
        count++;
        s.current_size++;
        c=is.get();
        if (!isdigit(c)) break;
    }

    return is;
}
//////////////////////////////////////////////////
void MyInt::Grow() {
    max_size = current_size + 5;
    int* temp = new int[max_size];
    for (int i=0;i<current_size;i++) {
        temp[i]=ints[i];
    }
    delete[] ints;
    ints = temp;
}

MyInt &MyInt::operator=(const MyInt & d) {
    if (this != &d)   // only copy if the object passed in is not already this one
    {
        delete [] ints;
        max_size = d.max_size;
        current_size = d.current_size;
        ints = new int[d.max_size];
        for (int i = 0; i < current_size; i++)
            ints[i] = d.ints[i];
    }
    return *this;     // return the object itself (by reference)
}

MyInt operator++(const MyInt &x) {
    MyInt temp = x;
    temp.ints[temp.current_size] += 1;

    return temp;
}



//void MyInt::Resize() {
//    current_size = current_size -1;
//    char* temp = new char[current_size+1];
//
//    for (int i=0;i<ints+1;i++) {
//        temp[i] = ints[i+1];
//    }
//    delete[] ints;
//    ints = temp;
//}



