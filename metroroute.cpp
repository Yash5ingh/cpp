#include<iostream>
using namespace std;

struct node
{
char stationName[50];
node *next;
};

class Stations
{
public:
node *head,*p,*q,*z;
Stations()
{
head = NULL;
p = NULL;
q = NULL;
z = NULL;
}
void addStation();
void displayRoute();
};

void Stations::addStation()
{
node *newStat = new node;
cout<<"Enter Station Name: ";
cin>>newStat->stationName;

if(head == NULL)
{
head = newStat;
newStat->next = NULL;
}
else
{
p = head;
while(p->next != NULL)
{
p = p->next;
}
p->next = newStat;
newStat->next = NULL;
}
}

void Stations::displayRoute()
{
q = head;
cout<<"Source-> ";
while (q->next != NULL)
{
cout<<q->stationName<<" -> ";
q = q->next;
}
cout<<q->stationName<<" <- Destination"<<endl;

}

int main()
{
Stations s1;
for(int i = 0; i<5; i++)
{
s1.addStation();
}

s1.displayRoute();

cout<<"\nAdd a new station:"<<endl;
s1.addStation();
s1.displayRoute();


}
