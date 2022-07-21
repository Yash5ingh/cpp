#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    char str[20],sear[20],a;
    string reading;
    fstream l,k,s;
    l.open("C:\\cllg\\filehan.txt",ios::out);
    if(!l)
    {
        cout<< "FILE NOT FOUND!";
        return 0;
    }
    cout<< "Enter somethin\n";
    cin.getline(str,20);
    l << str;
    l.close();

    k.open("C:\\cllg\\filehan.txt",ios::in);
    if(!l)
    {
        cout<< "FILE NOT FOUND!";
        return 0;
    }

    while(!k.eof())
    {
        getline(k,reading);
        cout<<reading;
    }
    k.close();


    s.open("C:\\cllg\\filehan.txt",ios::in);

    cout<< "\nEnter string to be searched: \n";
    cin.getline(sear,20);

    while(!s.eof())
    {
        getline(s,reading);
        if(reading.find(sear,0)!=string::npos)
        {
            cout<< "string FOUND!!";
        }
    }
    s.close();
    return 0;
}
