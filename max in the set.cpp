#include<iostream>
using namespace std;

int main()
{
    int sets[10];
    int n,maximum,first,last;
    cout<< "Enter the number of elements in the set: \n";
    cin >> n;
    for(int i=0; i < n; i++)
    {
        cout<< "Enter element "<< i+1<< " :\n";
        cin>> sets[i];
    }

    maximum = sets[0];
    first = 0;
    last = 0;
    for(int i=0; i < n; i++)
    {
        if(sets[i]==maximum)
        {
            last = i;
        }
        if(sets[i]>maximum)
        {
            maximum = sets[i];
            first = i;
            last = i;
        }
    }
    cout<< "\n\nSET = {";
    for(int i=0; i < n; i++)
    {
        cout<< sets[i]<<",";
    }
    cout<< "\b}";
    cout<< "\n\nmaximum = "<< maximum << endl;
    cout<< "first : "<< first << endl;
    cout<< "last : "<< last<< endl;

    return 0;
}
