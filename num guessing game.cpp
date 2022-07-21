#include<iostream>

using namespace std;

int main()
{
   int a,i,g;
   string h;
   cout<< "enter hint:\n";
   getline(cin , h);
   cout<< "Enter secret number:\n";
   cin>>a;
   cout<< "enter number of chances:\n";
   cin>> i;

   while(i>0)
   {
       cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
       cout<< "HINT:"<< h<< endl;
       cout<< "chances left : "<< i<< endl<< endl;
       cout<< "Enter your guess:\n";
       cin>> g;
       if(g==a)
       {
           cout<< "\n\n\n\nyou win!!\n\n";
           i=-1;
       }
       i--;

   }
   if(i==0)
       {
           cout<< "\n\n\n\n\n\n\n\n\nyou lose!\n"<< "secret number was:"<< a<< endl;
       }
    return 0;
}
