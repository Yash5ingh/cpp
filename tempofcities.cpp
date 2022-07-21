#include<iostream>
using namespace std;

class city
{
private:
    float temp[2][7];
    char cityname[2][20];
public:
    void getdata();
    void putdata();
};

void city::getdata()
{
    for(int n =0 ; n < 2 ; n++)
    {
    cout<< "\nEnter name of city:\n";
    cin>> cityname[n];
    for(int i=0 ; i < 7 ; i++)
    {
        cout<< "Enter temperature for Day "<<i+1<<endl;
        cin>> temp[n][i];
    }
    }
}

void city::putdata()
{
    for(int o=0 ; o < 2 ; o++)
    {
        cout<< "\nName of city : "<<cityname[o]<<endl;
    for(int i=0 ; i < 7 ; i++)
    {
        cout<< "\tDay "<<i+1<<": "<<temp[o][i] <<endl;
    }
    }
}

int main()
{
    city c;

    c.getdata();
    c.putdata();

    return 0;
}
