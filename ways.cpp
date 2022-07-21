#include <iostream>
using namespace std;

int way(int n,int m)
{
   if (n==0 || m==0)
    {
        return 1;
    }
    else
    {
        return way(n,m-1) + way(n-1,m) ;
    }
}

int main()
{
    int n, m;
    cout<< "enter coordinates (0,0) to (x,y)\n";
    cin>> n>>m;
    cout<< "\n\tno. of shortest path:  "<< way(n,m)<< "\n\n";
    return 0;
}
