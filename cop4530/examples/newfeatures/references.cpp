#include <iostream>
using namespace std;

void Func(const int & x);		// pass by const reference (Lvalue ref)
void Func(int && x);			// pass by r-value reference

int main()
{
   int x = 10, y = 20, z = 30;
   int & r = x;
   const int& cref = x + y;		// const ref can attach to r-value
//   int & Lref = x + y; 		// illegal -- Lvalue reference
   int && r2 = x + y;			// R-value ref can attach to r-value
  
   int array[10];

   // which version do these call?
   Func(x);		
   Func(array[4]);
   Func(x + y);
   Func(100);
}

void Func(const int & x)
{
   cout << "Runnning Function that passed by L-value reference\n";
}

void Func(int && x)
{
   cout << "Runnning Function that passed by R-value reference\n";
}
