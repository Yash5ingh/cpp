#include<iostream>
#include<fstream>
using namespace std;


int main()
{
    fstream a;
    string r;
    a.open("C:\\cllg\\xyz.txt",ios::out);
    a << "bas kar bhai";
    a.close();

    return 0;
}
