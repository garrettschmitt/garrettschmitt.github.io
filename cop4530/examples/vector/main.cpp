#include <iostream>
#include "vector.h"

using namespace std;

template <class T>
void printVect(const Vector<T>& list, ostream& out = cout)
{
   auto itr = list.begin();
   while (itr != list.end())
   {
      out << *itr << '\n';
      ++itr;
   }
}


int main()
{
   Vector<int> list1;
   Vector<double> list2;

   for (int i = 0; i < 20; i++)
   {
       list1.push_back(i*3 + 1);
       list2.push_back(i*2.2 + 1.5);
   }

   cout << "list1:\n";
   printVect(list1);
   cout << "list2:\n";
   printVect(list2);
}
