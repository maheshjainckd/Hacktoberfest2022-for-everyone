// tower of hanoi
#include <iostream>
using namespace std;
int tower(int n, string beg = " Rod1 ", string aux = " Rod2 ", string dest = " Rod3 ")
{
      static int i = 0;
      if (n > 0)
      {
            tower(n - 1, beg, dest, aux);
            cout << "Move disk " << n << " from" << beg << "to" << dest << "\n";
            i++;
            tower(n - 1, aux, beg, dest);
      }

      return i;
}
int main()
{
      int n;
      cin >> n;
      int steps = tower(n);
      cout << "Total number of steps = " << steps << "\n";
      return 0;
}