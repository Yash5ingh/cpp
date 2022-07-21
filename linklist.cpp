#include<iostream>
using namespace std;

int siz=0;

class node
{
public:
    int data;
    node* next;

    node()
    {
        cout<< "Enter number: \n";
        cin>> data;
        next = NULL;
    }
};

void addToHead(node* &head)
{
    node* n = new node;
    n->next = head;
    head = n;
    siz++;
}

void addToTail(node* &head)
{
    siz++;
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

}

void deleteNode(node* &head)
{
    siz--;
    int i=0,n;
    node* temp = head;
    if(temp==NULL)
    {
        cout<< "\n\nList is empty!!\n";
        return;
    }
    cout<< "Enter element you want to delete: \n";
    cin>> n;
    if(temp->data == n)
    {
        node* delNode = temp;
        head = temp->next;
        delete delNode;
        return;
    }
    while(temp->next->data!=n)
    {
        temp = temp->next;
        i++;
        if(i==siz)
        {
            cout<< "element not found!";
            siz++;
            return;
        }
    }
    node* delNode = temp->next;
    temp->next=temp->next->next;
    delete delNode;
}

void displayData(node* head)
{
    int i=1;
    node* temp = head;
    if(temp==NULL)
    {
        cout<< "\n\nList is empty!!\n";
        return;
    }
    cout<< "\n\n------------\n";
    while(temp != NULL)
    {
        cout<< "Data "<<i<<" = "<< temp->data<< endl;
        temp = temp->next;
        i++;
    }
    cout<< "------------\n";
}

void searching(node* head)
{
    int ser;
    cout<< "\n\nEnter number to search: \n";
    cin>> ser;
     node* temp = head;

    while(temp != NULL)
    {
        if(temp->data==ser)
        {
            cout<< "Element exists!\n";
            return;
        }
        temp = temp->next;
    }
        cout<< "Element does not exist!!";
}

void reverseList(node* &head)
{
    node* current = head;
    node* previous = NULL;
    node* next;

    while(current!=NULL)
    {
        next = current->next;
        current->next=previous;
        previous = current;
        current = next;
    }
    head = previous;
}

node* kreverse(node* &head,int k)
{
    node* current = head;
    node* previous = NULL;
    node* next;
    int counter =1;

    while(current!=NULL && counter <= k)
    {
        next = current->next;
        current->next=previous;
        previous = current;
        current = next;
        counter++;
    }
    if(next!=NULL)
    {
        head->next = kreverse(current,k);
    }
    return previous;
}

void detectCycle(node* head)
{
    node* slow = head;
    node* fast = head;

    while(fast!=NULL && fast->next!= NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
        {
            cout<< "\n\nCycle exists!!\n";
            return;
        }
    }
    cout<< "\n\nCycle does not exist!\n";
}

void createCycle(node* head)
{
    node* strt;
    node* tail;
    node* temp=head;
    int k,counter = 1;
    cout<< "Enter the point where the tail should connect: \n";
    cin>> k;

    while(temp != NULL)
    {
        if(k == counter)
        {
            strt = temp;
        }
        tail = temp;
        temp = temp->next;
        counter++;
    }
    tail->next = strt;
}

void removeCycle(node* head)
{
    node* slow = head;
    node* fast = head;
    bool found=false;

    while(fast!=NULL && fast->next!= NULL)
    {
        if(!found)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast == slow)
        {
            fast = head;
            found = true;
        }
        if(found)
        {
            if(fast->next == slow->next)
            {
                slow->next = NULL;
                return;
            }
            fast = fast->next;
            slow = slow->next;
        }
    }
}

void KlastToFirst(node* &head)
{
    node* newtail;
    node* newhead;
    node* temp = head;
    int counter = 1, k;
    cout<< "\n\nEnter how many nodes you want to shift forward: \n";
    cin>> k;

    while(temp->next!=NULL)
    {
        if(counter==k)
        {
            newhead = temp;
        }
        if(counter+1 == k)
        {
            newtail = temp;
        }
        temp = temp->next;
        counter++;
    }
    newtail->next = NULL;
    temp->next = head;
    head = newhead;
}

void insertBetween(node* &head)
{
    int ind,i=0;
    siz++;
    cout<< "Where do you want to insert: \n";
    cin>> ind;
    node* n = new node;
    node* temp=head;
    while(temp->next!=NULL)
    {
        i++;
        if(i==ind)
        {
            cout<< "yes";
            break;
        }
        temp = temp->next;
    }
    n->next= temp->next;
    temp->next = n;
}

void freq(node* head)
{
    int ser,freqency=0;
    cout<< "\n\nEnter data: \n";
    cin>> ser;
     node* temp = head;

    while(temp != NULL)
    {
        if(temp->data==ser)
        {
            freqency++;
        }
        temp = temp->next;
    }
        cout<< "Element appeared : "<< freqency << " times\n";
}

int main()
{
    node* head=NULL;

    int q;
    bool run = true;
    while(run)
    {
        cout << "\n\n1. Add to head\n2. Add to tail\n3. Print\n4. Search\n5. Delete node\n6. Reverse\n7. K Reverse\n8. Detect cycle\n9. Create cycle\n10. Remove cycle\n11. last to first\n12. Insert in between\n13. Frequency\n0. EXIT\n\nEnter choice:\n";
        cin>> q;
        switch(q)
        {
        case 1:
            {
                addToHead(head);
                break;
            }
        case 2:
            {
                addToTail(head);
                break;
            }
        case 3:
            {
                displayData(head);
                break;
            }
        case 4:
            {
                searching(head);
                break;
            }
        case 5:
            {
                deleteNode(head);
                break;
            }
        case 6:
            {
                reverseList(head);
                break;
            }
        case 7:
            {
                int k;
                cout<< "\n\nEnter value of K: \n";
                cin>> k;
                head = kreverse(head,k);
                break;
            }
        case 8:
            {
                detectCycle(head);
                break;
            }
        case 9:
            {
                createCycle(head);
                break;
            }
        case 10:
            {
                removeCycle(head);
                break;
            }
        case 11:
            {
                KlastToFirst(head);
                break;
            }
        case 12:
            {
                insertBetween(head);
                break;
            }
        case 13:
            {
                freq(head);
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
