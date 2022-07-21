#include<iostream>
using namespace std;


class StackClass
{
private:
    int Stack[20];
    int Max;
    int topofStack=-1;
public:
    StackClass()
    {
        cout<< "Enter max size of stack: \n";
        cin>> Max;
    }

    void push();
    void put();
    void pop();
    void clearStack();
    void getTop();
    void currentSize();

}s;

void StackClass::push()
{
    if(Max-1>topofStack)
    {
        int num;
        cout<< "Enter value at index "<< topofStack+1 << ": \n";
        cin>> num;
        topofStack++;
        Stack[topofStack]=num;
    }
    else
    {
        cout<< "The stack is full!!\n";
    }
}

void StackClass::put()
{
    for(int i=topofStack; i>=0; i--)
    {
        cout<< "[" << i << "] : " << Stack[i]<< endl;
    }
}

void StackClass::pop()
{
    if(topofStack > -1)
    {
        cout<< "Deleted element :-  ";
        cout<< "[" << topofStack << "] : " << Stack[topofStack]<< endl;
        topofStack--;
    }
    else
    {
        cout<< "\nStack is empty!!\n";
    }
}

void StackClass::clearStack()
{
    if(topofStack > -1)
    {
        topofStack=-1;
    }
    else
    {
        cout<< "\nstack is empty!!\n";
    }
}

void StackClass::getTop()
{
    if(topofStack > -1)
    {
        cout<< Stack[topofStack];
    }
    else
    {
        cout<< "\nstack is empty!!\n";
    }
}

void StackClass::currentSize()
{
    cout<< "\n\nThere are "<< topofStack+1 << " elements in the stack.\n";
}

int main()
{
    int ch;

    do
    {
        cout<<"\n\n1) Push"<<endl;
        cout<<"2) Pop"<<endl;
        cout<<"3) Display"<<endl;
        cout<<"4) Clear"<<endl;
        cout<<"5) Top element"<<endl;
        cout<<"6) Current size"<<endl;
        cout<<"0) Exit"<<endl;
        cout<<"Enter your choice:\n"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                {
                    s.push();
                    break;
                }


            case 2:
                {
                    s.pop();
                    break;
                }

            case 3:
                {
                    s.put();
                    break;
                }
            case 4:
                {
                    s.clearStack();
                    break;
                }
            case 5:
                {
                    s.getTop();
                    break;
                }
            case 6:
                {
                    s.currentSize();
                    break;
                }
            case 0:
                {
                    cout<<"\n\nExit"<<endl;
                    break;
                }
            default:
                {
                    cout<< "Invalid choice";
                }
      }
   }while(ch!=0);

    return 0;
}
