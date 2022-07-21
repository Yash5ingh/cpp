#include<iostream>
using namespace std;

class stacklinklist
{
private:
struct node
{
    node* next;
    int data;
};
node* head;
node* temp;
node* cur;

public:
   stacklinklist()
   {
       head = NULL;
       temp = NULL;
       cur = NULL;
   }
void push();
void pop();
void printStack();
};

void stacklinklist::printStack()
{
    if(head==NULL)
    {
        cout<< "Stack is empty!";
        return;
    }
    int coun =0;

    temp = head;
    cout<< "\nSTACK:\n";
    while(temp != NULL)
    {
        coun++;

        cout<<coun<<". "<< temp->data << endl;
        temp = temp->next;
    }
}

void stacklinklist::push()
{
    node* n = new node;
    cout<< "Enter data: \n";
    cin>> n->data;
    n->next = NULL;
    if(head!=NULL)
    {
        n->next = head;
        head = n;
    }
    else
    {
        head = n;
    }
}

void stacklinklist::pop()
{
    temp = head;
    head = head->next;
    temp = NULL;
}

int main()
{
    stacklinklist s1;

    int q;
    bool run = true;
    while(run)
    {
        cout << "\n\n1. Push\n2. Pop\n3. Print\n0. EXIT\n\nEnter choice:\n";
        cin>> q;
        switch(q)
        {
        case 1:
            {
                s1.push();
                break;
            }
        case 2:
            {
                s1.pop();
                break;
            }
        case 3:
            {
                s1.printStack();
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
