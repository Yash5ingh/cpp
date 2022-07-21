#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
    node* prev;

    node()
    {
        cout<< "Enter data: \n";
        cin>> data;
        next = NULL;
        prev = NULL;
    }
};

class LL
{
public:
    node* head=NULL;

    void addToHead();
    void addToTail();
    void displayData();
    void deleteNode();
    void deleteData();
};

void LL::addToHead()
{
    node* n = new node;

    if(head==NULL)
    {
        head = n;
        return;
    }

    n->next = head;
    head->prev = n;
    head = n;

}

void LL::addToTail()
{

    node* n = new node;

    if(head==NULL)
    {
        head = n;
        return;
    }
    node* temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;

}

void LL::displayData()
{
    node* temp = head;
    if(temp==NULL)
    {
        cout<< "\n\nList is empty!!\n";
        return;
    }
    cout<<"NULL <--> ";
    while(temp != NULL)
    {
        cout<< temp->data<<" <--> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void LL::deleteNode()
{
    int n;
    node* temp = head;

    if(temp==NULL)
    {
        cout<< "\n\nList is empty!!\n";
        return;
    }

    cout<< "Enter index you want to delete: \n";
    cin>> n;

    if(n==0)
    {
        node* delNode = temp;
        head = temp->next;
        delete delNode;
        return;
    }
    while(n-1!=0 && temp!=NULL)
    {
        temp = temp->next;
        n--;
        cout<< "hello\n";
    }
    node* delNode = temp->next;
    temp->next=temp->next->next;
    if(temp->next != NULL)
    {
        temp->next->prev = temp;
    }
    delete delNode;
}

void LL::deleteData()
{
    int n,q;
    node* temp = head;
    bool deleteFirst = true;

    if(temp==NULL)
    {
        cout<< "\n\nList is empty!!\n";
        return;
    }

    cout<< "Enter data you want to delete: \n";
    cin>> n;
    cout<< "Do you want to delete all occurrences?\nyes-1\nno-0 \n";
    cin>> q;
    if(q==1)
    {
        deleteFirst=false;
    }


    while(temp->next!=NULL)
    {
        while(temp->data == n)
        {
            head = temp->next;
            delete temp;
            head->prev = NULL;
            if(deleteFirst)
            {
                return;
            }
            temp = head;
        }
        if(temp->next->data==n)
        {
            node* delNode = temp->next;
            temp->next=temp->next->next;
            if(temp->next != NULL)
            {
                temp->next->prev = temp;
            }
            delete delNode;
            if(deleteFirst)
            {
                return;
            }
            temp = head;
        }
        cout<< "hello";
        temp = temp->next;
    }
}

int main()
{
    LL list1;

    int q;
    bool run = true;
    while(run)
    {
        cout << "\n\n1. Add to head\n2. Add to tail\n3. Print\n4. Delete\n5. Delete Using Data\n0. EXIT\n\nEnter choice:\n";
        cin>> q;
        switch(q)
        {
        case 1:
            {
                list1.addToHead();
                break;
            }
        case 2:
            {
                list1.addToTail();
                break;
            }
        case 3:
            {
                list1.displayData();
                break;
            }
        case 4:
            {
                list1.deleteNode();
                break;
            }
        case 5:
            {
                list1.deleteData();
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
