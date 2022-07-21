#include<iostream>
using namespace std;

int part(int a[],int l,int r)
{
    int pivot,i,j,temp;

    pivot = a[r];
    i = l-1;

    for(j=l; j<=r-1; j++)
    {
        if(a[j]<pivot)
        {
            i++;
            temp= a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i+1];
    a[i+1] = a[r];
    a[r] = temp;

    return i+1;
}

void quickSort(int a[],int l,int r)
{
    int p;
    if(l<r)
    {
        p = part(a,l,r);

        quickSort(a,l,p-1);
        quickSort(a,p+1,r);
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
        cout<< "Enter element "<<i <<" :\n";
        cin>>ar[i];
    }

    cout<< "\nUnsorted Array :";
    for(int i=0; i<n ; i++)
    {
        cout<<ar[i]<<",";
    }
    cout<<"\b \n";

    quickSort(ar, 0, n-1);

    cout<< "\nSorted Array :";
    for(int i=0; i<n ; i++)
    {
        cout<<ar[i]<<",";
    }
    cout<<"\b \n";

    return 0;
}
