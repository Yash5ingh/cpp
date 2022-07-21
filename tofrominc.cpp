#include<iostream>
using namespace std;

class series
{
private:
    int increment,from,to;
public:
    void getdata();
    void putdata();
}s;

void series::getdata()
{
    cout << "Enter starting point of series:\n";
    cin>>from;
    cout << "Enter end point of series:\n";
    cin>>to;
    cout << "Enter increment:\n";
    cin>>increment;
}

void series::putdata()
{
    cout<< "[";
    for(int i=from; i<=to; i+=increment)
    {
        cout<< i<<",";
    }
    cout<< "\b]";
}

int main()
{
    s.getdata();
    s.putdata();
    return 0;
}
