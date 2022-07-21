#include<iostream>
using namespace std;
struct Node
{
    int prior;
    int age;
    char Name[20];
    char Gender[10];
    Node *next;
};
class Hospital
{
    Node *front,*temp,*p,*q,*r;
    public:
    Hospital()
    {
        p=NULL;
        q=NULL;
        r=NULL;
        front=NULL;
    }
    public:
    void Enqueue();
    void MedPri();
    void Display();
};
void Hospital::Enqueue()
{
    Node *p=new Node;
    cout<<"Enter the name of the patient: "<<endl;
    cin>>p->Name;
    cout<<"Enter the age of the patient: "<<endl;
    cin>>p->age;
    cout<<"Enter the Gender of the patient: "<<endl;
    cin>>p->Gender;
    cout<<"Enter the priority of the patient according to below given list: "<<endl;
    cout<<"i)Serious illness(Top Priority)  1 "<<endl;
    cout<<"ii)Medium illness(Medium Priority) 2 "<<endl;
    cout<<"iii) General illness(Least priority) 3 "<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>p->prior;
    if((front==NULL)|| (p->prior<front->prior))
    {
        p->next=front;
        front=p;
    }
    else
    {
        temp=front;
        while((temp->next!=NULL) && (temp->next->prior<=p->prior))
        {
            temp=temp->next;
        }
        p->next=temp->next;
        temp->next=p;
    }
    cout<<"Entry entered."<<endl;
    cout<<"\n\n"<<endl;
}

void Hospital::Display()
{
    p=front;
    q=front;
    cout<<"Priority\t   Name of patient\t   Age of patient\t   Gender of patient"<<endl;
    while(q->next!=NULL)
    {
        cout<<"   "<<q->prior<<"\t\t\t"<<q->Name<<"\t\t\t"<<q->age<<"\t\t\t"<<q->Gender<<endl;
        q=q->next;
    }
    cout<<"   "<<q->prior<<"\t\t\t"<<q->Name<<"\t\t\t"<<q->age<<"\t\t\t"<<q->Gender<<endl;
    cout<<"\n\n"<<endl;
}

void Hospital::MedPri()
{
    p=front;
    q=front;
    cout<<"Priority\t   Name of patient\t   Age of patient\t   Gender of patient"<<endl;
    while(q!=NULL)
    {
        if(q->prior==2)
        {
            cout<<"   "<<q->prior<<"\t\t\t"<<q->Name<<"\t\t\t"<<q->age<<"\t\t\t"<<q->Gender<<endl;
        }
        q=q->next;
    }
    cout<<"\n\n"<<endl;
}

int main()
{
    Hospital p;
    int choice;
    while(1)
    {
     cout<<"Enter the choice:"<<endl;
     cout<<"a> Enter the entry   [1]"<<endl;
     cout<<"b> Display Medium Priority  [2]"<<endl;
     cout<<"c> Display all entry [3]"<<endl;
     cout<<"d> Exit              [0]"<<endl;
     cout<<"Your choice:-"<<endl;
     cin>>choice;
     if(choice==1)
        p.Enqueue();
     else if(choice==2)
        p.MedPri();
     else if(choice==3)
        p.Display();
     else if(choice==0)
        exit(0);
    }
}
