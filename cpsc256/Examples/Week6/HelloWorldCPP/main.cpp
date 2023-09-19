/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.cpp
 * Author: brash
 *
 * Created on October 4, 2021, 5:42 AM
 */


// the libraries in C++ are a bit different than in C
#include <iostream> // cout, endl, fixed
#include <iomanip> // setprecision, setw
#include <cmath> // C math library functions
#include <string> // The string class

// The namespace std is required for cout, endl, etc.
//
// If you don't want to use the namespace std, then you can
// use the following syntax:
//
// std::cout << "Hello World!" << std::endl;

using namespace std;

int main(int argc, char** argv) {
    
    cout << "Hello World!" << endl;

    // The primitive data types in C++ are the same as in C
    int a=14657;
    float b = 0.54;
    double c = 4.5678902392;

    // The cout command is used to print to the screen
    cout << endl;
    cout << "a = " << a << " b = " << b << " c = " << c << endl;
    cout << endl;


    // the setprecision command is used to set the number of digits
    // by default, the argument is the number of significant digits
    cout << "c = " << setprecision(5) << c << endl;
    cout << "c = " << setprecision(9) << c << endl;

    // the fixed command is used to specify that
    // with setprecision, the argument will instead be
    // the number of digits after the decimal
    cout << fixed;
    cout << endl;
    
    cout << "b = " << setprecision(5) << b << endl;
    cout << "b = " << setprecision(9) << b << endl;

    // the scientific command is used to print in scientific notation
    cout << scientific;
    cout << endl;
    
    cout << "c = " << setprecision(5) << c << endl;
    cout << "c = " << setprecision(9) << c << endl;
    cout << endl;

    // To get input from the user, we use the cin command
    // Note that the >> operator is used to read in the input
    int i,j;
    cout << "Enter a number:" << endl;
    cin >> i;
    cout << "Enter another number:" << endl;
    cin >> j;
    
    cout << "The numbers are " << i << " and " << j << endl;
    
    int k1, k2, k3;
    double d = 2.0;
    double e = 2.5;
    k1 = static_cast<int>(d*e*e);
    k2 = (int)(d*e*e);
    k3 = d*e*e;

    // Note that the static_cast command is used to convert
    // a double to an int ... this is a C++ command, and
    // is not available in C.  In principle, we could use
    // the C command:
    //      k2 = (int)(d*e*e);
    // but this is not recommended.
    // And, we could also just use:
    //      k3 = d*e*e;
    // but this is also not recommended.

    cout << "The integer k1 is " << k1 << endl;
    cout << "The integer k2 is " << k2 << endl;
    cout << "The integer k3 is " << k3 << endl;
    cout << endl;
    cout << "The integer k1^2 is " << pow(k1,2) << endl;
    cout << endl;

    // In the case above, we see that there is no difference
    // between k1, k2, and k3, so you might think - why bother?

    // The real reason to use static_cast is when you are
    // using pointers.  The static_cast command allows compile-time
    // checking of the type of the pointer, and will throw an error
    // if you try to use a pointer of one type to point to a variable
    // of another type.

    char one_byte_char = 65; //1-byte data. ASCII of ‘A’
    int* ptr = (int*)&one_byte_char; //4-byte

    cout << "The value of one_byte_char is " << one_byte_char << endl;
    cout << "The value of ptr is " << ptr << endl;

    // The following will throw a compile time error!

    //char one_byte_char2 = 65; //1-byte data. ASCII of ‘A’
    //int* ptr2 = static_cast<int>(&one_byte_char2); //4-byte

    //cout << "The value of one_byte_char2 is " << one_byte_char2 << endl;
    //cout << "The value of ptr2 is " << ptr2 << endl;

    // The string class exists in C++, and is not available in C!!!!
    string s1,s2,s3;
    
    cout << "Enter a name on a single line" << endl;
    
    cin >> s1;
    cin >> s2;
    
    cout << "S1 = <" << s1 << ">" << endl;
    cout << "S2 = <" << s2 << ">" << endl;
    
    
    string sphrase;
    
    cout << "Enter a name on a single line: " << endl;
    
    cin.ignore();
    getline(cin,sphrase);
    
    cout << "Name = <" << sphrase << ">" << endl;

    return 0;
}

