#include<iostream>
#include<math.h>
using namespace std;


class polynomeal
{
private:
    int order,coefficient[10],exponent[10];
public:
    void getdata();
    void putdata();
    void addpoly();
    void evaluate();
}p[5];

void polynomeal::getdata()
{
    cout<< "\n\nEnter order of polynomial: \n";
    cin>> order;
    for(int i=order+1; i>=0; i--)
    {
        exponent[i] = order-i;
    }
    for(int i=0; i < order+1; i++)
    {
        cout << "Enter coefficient for x^"<< exponent[i]<<endl;
        cin>> coefficient[i];
    }
}

void polynomeal::putdata()
{
    cout<< "\nPolynomial = ";
    for(int i=0; i < order; i++)
    {
        if(coefficient[i] != 0 )
        {
            if(exponent[i]==1)
                {
                if(coefficient[i+1]<0)
                    {
                        cout << coefficient[i]<< "x";
                    }
                else
                    {
                        cout << coefficient[i]<< "x"<<"+";
                    }
                }
            else
                {
                if(coefficient[i+1]<0)
                    {
                        cout << coefficient[i]<< "x^"<< exponent[i];
                    }
                else
                    {
                        cout << coefficient[i]<< "x^"<< exponent[i]<<"+";
                    }
                }
        }
    }

    cout<< coefficient[order]<<endl;
}

void polynomeal::addpoly()
{
    p[1].getdata();
    cout<< "\n\nAdding: ";
    p[1].putdata();
    cout<< "\t+";
    p[0].putdata();

    if(order<p[1].order)
    {
        int red = 0;
        for(int i= p[1].order; i>= p[1].order-order ; i--)
        {
            coefficient[i] = coefficient[order-red];
            red++;
        }
        for(int i = order-red+1; i >=0; i--)
        {
            coefficient[i]=0;
        }
        order = p[1].order;
        for(int i=order+1; i>=0; i--)
        {
            exponent[i] = order-i;
        }
    }

    for(int i=0; i <= order; i++)
    {
        coefficient[i] += p[1].coefficient[i];
    }
    cout<<"--------------";
    p[0].putdata();

}

void polynomeal::evaluate()
{
    int valx,result=0;
    cout<< "Enter value of x: \n";
    cin>> valx;
    for(int i=0; i<= order; i++)
    {
        result += coefficient[i]*( pow(valx, exponent[i]) );
    }
    cout<< "RESULT= "<< result<<endl;
}


int main()
{
    int q;
    bool run = true;
    while(run)
    {
        cout << "\n\n1. Input\n2. Print\n3. Evaluate\n4. Add\n\n0. EXIT\n\nEnter choice:\n";
        cin>> q;
        switch(q)
        {
        case 1:
            {
                p[0].getdata();
                break;
            }
        case 2:
            {
                p[0].putdata();
                break;
            }
        case 3:
            {
                p[0].evaluate();
                break;
            }
        case 4:
            {
                p[0].addpoly();
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
