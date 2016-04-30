#include <iostream>
using namespace std;

#include "intvect.h"

int main()
{
   IntVector v1;		// empty
   IntVector v2(20);	// empty, capacity 20
   int list1[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
   int list2[8] = {100,200,300,400,500,600,700,800};

   for (int i = 0; i < 15; i++)
	v1.Insert(list1[i]);

   for (int i = 0; i < 8; i++)
	v2.Insert(list2[i]);
   cout << "CHECKPOINT A\n";

   IntVector v3 = v1;			// copy constructor
   IntVector v4 {2, 4, 6, 8, 10, 12, 14};	// initializer list constructor

   cout << "v1 = " << v1 << '\n';
   cout << "v2 = " << v2 << '\n';
   cout << "v3 = " << v3 << '\n';

   cout << "CHECKPOINT B\n";
   IntVector v5;
   v5 = {3, 6, 9, 12, 15};

   cout << "CHECKPOINT C\n";
   v5 = v1 + v2;		
   


}
