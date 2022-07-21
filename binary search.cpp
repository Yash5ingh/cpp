#include<iostream>
using namespace std;

int binarySearch(int n, int a[],int k)
{
    int s=0, e=n-1, mid;
    while(s<=e)
    {
        mid = (s+e)/2;

        if(a[mid] == k)
        {
            return mid;
        }
        else if(a[mid] > k)
        {
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return -1;
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

    cout<< "\nARRAY:";
    for(int i=0; i<n ; i++)
    {
        cout<<ar[i]<<",";
    }
    cout<<"\b \n";

    int key;
    cout<<"Enter key: \n";
    cin>> key;

    int res;
    res = binarySearch(n,ar,key);

    if(res == -1)
    {
        cout<< "dosen't exist\n";
    }
    else{
        cout<< key<< " exist on index "<< res<< " in the array\n";
    }

    return 0;
}
