#include<iostream>
using namespace std;

class arr
{
private:
    int l;
    int a[50];
public:
    void getData();
    void putData();
    void searchElement();
    void insertElement();
    void deleteElement();
    void maxElement();
    void minElement();
};

void arr::getData()
{
    cout<<"Enter size of array(max 50): \n";
    cin>> l;
    for(int i=0; i < l ; i++)
    {
        cout<< "Enter element "<<i+1<<endl;
        cin>>a[i];
    }
}

void arr::putData()
{
    cout<< "\n\nArray = [";
    for(int i=0; i < l ; i++)
    {
        cout<< a[i]<<",";
    }
    cout<< "\b]\n";
}

void arr::searchElement()
{
    int e;
    bool exists = false;
    cout<< "\n\nEnter element to be searched\n";
    cin>>e;
    for(int i = 0 ; i < l ; i++)
    {
        if(e==a[i])
        {
            cout<< "\nElement "<< e<< " exists on index "<<i<< endl;
            exists = true;
        }
    }
    if (!exists)
    {
        cout<< "\nElement does not exist\n";
    }
}

void arr::insertElement()
{
    int e,i;
    cout<< "\n\nEnter element to be inserted\n";
    cin>>e;
    cout<< "Enter index\n";
    cin>>i;

    if (i>l)
    {
        cout <<"max size reached!\n";
        return;
    }
    l++;
    for(int o = l-1 ; o > i ; o--)
    {
        a[o]= a[o-1];
    }
    a[i]= e;
}

void arr::deleteElement()
{
    int i;
    cout<< "\nEnter index to be deleted\n";
    cin>>i;

    if (i>l)
    {
        cout <<"max size reached!\n";
        return;
    }
    l--;
    for(int o = i ; o < l ; o++)
    {
        a[o]= a[o+1];
    }
}

void arr::maxElement()
{
    int n=a[0];

    for(int i = 0; i < l; i++)
    {
        if(n < a[i])
        {
            n= a[i];
        }
    }
    cout<< "\n\nHighest element = "<<n<< endl;
}

void arr::minElement()
{
    int n=a[0];

    for(int i = 0; i < l; i++)
    {
        if(n > a[i])
        {
            n = a[i];
        }
    }
    cout<< "\n\nLowest element = "<<n<< endl;
}

int main()
{
    arr s;
    int q;
    bool run = true;
    while(run)
    {
        cout << "\n\n1. Input array\n2. Print array\n3. Search\n4. Insert\n5. Delete\n6. Max value\n7. Min value\n0. EXIT\n\nEnter choice:\n";
        cin>> q;
        switch(q)
        {
        case 1:
            {
                s.getData();
                break;
            }
        case 2:
            {
                s.putData();
                break;
            }
        case 3:
            {
                s.searchElement();
                break;
            }
        case 4:
            {
                s.insertElement();
                break;
            }
        case 5:
            {
                s.deleteElement();
                break;
            }
        case 6:
            {
                s.maxElement();
                break;
            }
        case 7:
            {
                s.minElement();
                break;
            }
        case 0:
            {
                run = false;
                break;
            }
        default:
            {
                cout<< "\nInvalid choice\n\n";
            }
        }
    }
    return 0;
}
