#include <iostream>
using namespace std;

int way(int n)
{
      if(n==1 || n==0)
      {
          return 1;
      }

      else
      {
          return (n-1)*(way(n-2)) + way(n-1);
      }
}

int main()
{
    int n, m;
    cout<< "enter number of people\n";
    cin>> n;
    cout<< "\n\t"<< way(n)<< "\n\n";
    return 0;
}
