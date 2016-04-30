#include <iostream>
using namespace std;

int main()
{
   int array[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

   cout << "Output array:\n";
   for (int x: array)
     cout << x << '\n';

   cout << "Change array:\n";
   for (int x: array)
      x = x * 3;

   cout << "Output array:\n";
   for (int x: array)
     cout << x << '\n';


   cout << "Change array (second attempt):\n";
   for (int& x: array)
      x = x * 3;

   cout << "Output array:\n";
   for (int x: array)
     cout << x << '\n';


   


}
