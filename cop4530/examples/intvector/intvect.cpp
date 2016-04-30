#include <iostream>
#include <utility>		// for swap(), move()
#include "intvect.h"

using std::ostream;
using std::cout;

/*
    int * arr;			// pointer to dynamic array
    int max;			// allocated size of array
    int size;			// how many items in vector (used portion)
*/

ostream& operator<< (ostream& os, const IntVector& v)
{
   if (v.size == 0)
	return os << "Empty vector";

   // otherwise
   os << "{" << v.arr[0];
   for (int i = 1; i < v.size; i++)
      os << ", " << v.arr[i];

   return os << "}";
}

IntVector operator+(const IntVector& v1, const IntVector& v2)
{
   int newsize = v1.size + v2.size;
   IntVector result(newsize + 5);	// allocate
   for (int i = 0; i < v1.size; i++)
	result.Insert(v1.arr[i]);
   for (int i = 0; i < v2.size; i++)
	result.Insert(v2.arr[i]);
   return result;
}

IntVector::IntVector()
// default vector will have 10 capacity, 0 entries
{
   max = 10;			// default capacity
   size = 0;			// no items yet
   arr = new int[max];		// starting allocation
}

IntVector::IntVector(unsigned int c)
// starting vector is c capacity, 0 entries
{
   max = c;			// default capacity
   size = 0;			// no items yet
   arr = new int[max];		// starting allocation
}

IntVector::IntVector(initializer_list<int> list)
{
   cout << "Calling constructor for init list\n";
   max = 10;
   size = 0;
   arr = new int[max];

   for (auto x : list)
      Insert(x);
}

IntVector::~IntVector()
{
   if (arr != 0)	// if not null pointer
      delete [] arr;	// clean up
}

IntVector::IntVector(const IntVector& v)
// copy constructor (deep copy)
{
   cout << "Calling copy constructor\n";
   Clone(v);		// call helper function for deep copy
}

IntVector& IntVector::operator=(const IntVector& v)
{
   cout << "Calling assignment operator (deep copy)\n";
   if (this != &v)		// if not self-assignment
   {
      delete[] arr;		// clean up old array
      Clone(v);			// make deep copy
   }

   return *this;		// return calling obj, for cascading
}
/*
// MOVE constructor
IntVector::IntVector(IntVector&& v)
{
   cout << "Calling Move Constructor\n";
   

}

// MOVE assignment
IntVector& IntVector::operator=(IntVector&& v)
{
   cout << "Calling Move Assignment\n";


   return *this;
}
*/  

void IntVector::Insert(int val)
{
   if (max == size)		// if vector full
	Resize(size + 10);	// increase allocation
   arr[size] = val;		// insert val into array
   size++;
}

void IntVector::Resize(unsigned int newsize)
// resize array to given newsize
{
   max = newsize;
   int * temp = new int[max];			// build new array
   for (int i=0; i < max && i < size; i++)	// copy data
      temp[i] = arr[i];
   delete [] arr;				// delete old array
   arr = temp;					// rename
}

void IntVector::Clone(const IntVector& v)
// basic deep copy, for use in copy constructor and assignment operator
{
   max = v.max;
   size = v.size;
   arr = new int[max];
   for (int i = 0; i < size; i++)
       arr[i] = v.arr[i];
}
