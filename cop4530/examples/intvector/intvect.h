#include <iostream>
using std::ostream;

#include <initializer_list>
using std::initializer_list;

class IntVector
{
    friend ostream& operator<< (ostream& os, const IntVector& v);

    // concatenation of two vectors
    friend IntVector operator+(const IntVector& v1, const IntVector& v2);

public:
    IntVector();			// constructor (default)
    explicit IntVector(unsigned int c); // build vector with starting capacity c
    IntVector(initializer_list<int>);	// for init lists

    ~IntVector();			// destructor

    // deep copy functions
    IntVector(const IntVector& v);		// copy constructor
    IntVector& operator=(const IntVector& v);	// assignment operator
/*
    // MOVE functions
    IntVector(IntVector&& v);			// move constructor
    IntVector& operator=(IntVector&& v);	// move assignment 
*/  
    void Insert(int val);		// insert val into the vector

private:
    int * arr;			// pointer to dynamic array
    unsigned int max;		// allocated size of array
    unsigned int size;		// how many items in vector (used portion)

    void Resize(unsigned int newsize);	// resize the array
    void Clone(const IntVector& v);	// helper function
};		// end IntVector

