#include<iostream>
using namespace std;

void insertionSort(int a[],int n)
{
    int cur,j;
    for(int i = 1 ; i<n; i++)
    {
        cur = a[i];
        j = i-1;

        while(a[j]>cur && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1] = cur;
    }
}

int main()
{
    int n;
    cout<< "Enter size of array: \n";
    cin>>n;

    int ar[n];

    for(int i=0; i<n ; i++)
    {
        cout<< "Enter element\n";
        cin>>ar[i];
    }

    cout<< "\nUnsorted Array :";
    for(int i=0; i<n ; i++)
    {
        cout<<ar[i]<<",";
    }
    cout<<"\b \n";

    insertionSort(ar,n);

    cout<< "\nSorted Array :";
    for(int i=0; i<n ; i++)
    {
        cout<<ar[i]<<",";
    }
    cout<<"\b \n";

    return 0;
}
