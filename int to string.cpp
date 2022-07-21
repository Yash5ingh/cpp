#include <iostream>
using namespace std;

int intlen(int n)
{
    int c=0;
    while (n!=0)
    {
        n=n/10;
        c++;
    }
    return c;
}

int main()
{
    int a , al,b ,bl ,c, d;
    cout << "give two numbers\n";
    cin>>a >> b;

    al=intlen(a);
    bl=intlen(b);

    string sa(al,'0'), sb(bl, '0');

    for(int i=al-1 ; i>=0 ; i--)
    {
        d= a%10;
        a= a/10;
        sa[i]= d+48;
    }

    for(int i=bl-1 ; i>=0 ; i--)
    {
        d= b%10;
        b= b/10;
        sb[i]= d+48;
    }

    cout<< "(" << sa<< "," << sb<< ")"<< endl ;

    return 0;
}
