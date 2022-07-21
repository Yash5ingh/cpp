#include<iostream>
using namespace std;

class cirQueue
{
private:
    int fro=0 , rea=-1;
    int Q[20];
    int Max,coun=0;
public:
    cirQueue()
    {
        cout<< "Enter max size of queue: \n";
        cin>> Max;
    }

    void enQueue();
    void put();
    void deQueue();
    void currentSize();
    void frontElement();
}s;

void cirQueue::enQueue()
{
    if(coun == Max)
    {
        cout<<"Queue if full!\n";
    }
    else
    {
        coun++;
        if(rea == Max-1)
        {
            rea=0;
        }
        else
        {
            rea++;
        }
        cout<< "Enter value to enter in queue\n";
        cin>> Q[rea];
    }
}

void cirQueue::deQueue()
{
    if(coun == 0)
    {
        cout<< "Queue is empty!\n";
    }
    else
    {
        coun--;
        if(fro == Max-1)
        {
            fro = 0;
        }
        else{
            fro++;
        }
    }
}

void cirQueue::put()
{
    if(coun==0)
    {
        cout<< "Queue is empty!!";
    }
    else
    {
        int p = fro;
        for(int i=0 ; i<coun ; i++)
        {
            cout<< " ---> "<< Q[p];

            if(p == Max-1)
            {
                p = 0;
            }
            else
            {
                p++;
            }
        }
    }

}

void cirQueue::currentSize()
{
    cout<< "CURRENT SIZE: "<< coun;
}

void cirQueue::frontElement()
{
    if(coun==0)
    {
        cout<< "Queue is empty!!";
    }
    else
    {
        cout<< "FRONT ELEMENT: "<< Q[fro];
    }
}

int main()
{
    int ch;

    do
    {
        cout<<"\n\n1) Enqueue"<<endl;
        cout<<"2) Dequeue"<<endl;
        cout<<"3) Display"<<endl;
        cout<<"4) Size"<<endl;
        cout<<"5) Front element"<<endl;
        cout<<"0) Exit"<<endl;
        cout<<"Enter your choice:\n"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                {
                    s.enQueue();
                    break;
                }


            case 2:
                {
                    s.deQueue();
                    break;
                }

            case 3:
                {
                    s.put();
                    break;
                }
            case 4:
                {
                    s.currentSize();
                    break;
                }
            case 5:
                {
                    s.frontElement();
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
