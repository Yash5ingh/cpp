#include<iostream>

using namespace std;

int main()
{
    int n,t;
    cout<< "enter no. of elements\n";
    cin>>n;

    int a[n];

    cout<< "enter elements\n";

    for(int o=0; o<n ; o++)
    {
        cin>>a[o];
    }
    cout<< "\n\ngiven:\n";

    for(int o=0; o<n ; o++)
    {
        cout<< a[o] << "  ";
    }

    for (int i=0 ; i<n ; i++)
    {


        for (int j=i; j <n ; j++)
        {
            if (a[i]>a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
                j=i;
            }
        }
    }
    cout<< "\n\nsorted:\n";

    for(int o=0; o<n ; o++)
    {
        cout<< a[o] << "  ";
    }

     cout<< "\n\n";


    return 0;
}
