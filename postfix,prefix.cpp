#include<iostream>
using namespace std;

class stacklinklist
{
private:
struct node
{
    node* next;
    char data;
    int intdata;
};
node* head;
node* temp;

public:
   stacklinklist()
   {
       head = NULL;
       temp = NULL;
   }
void push(char);
void pushin(int);
void pop();
void printStack();
void infixToPostfix();
void infixToPrefix();
void postfixEval();
void prefixEval();
}s1;

void stacklinklist::printStack()
{
    if(head==NULL)
    {
        cout<< "Stack is empty!\n";
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

void stacklinklist::push(char c)
{
    node* n = new node;

    n->data = c;
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

void stacklinklist::pushin(int c)
{
    node* n = new node;

    n->intdata = c;
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
    if(head!=NULL)
    {
        temp = head;
        head = head->next;
        temp = NULL;
    }
}

void stacklinklist::infixToPostfix()
{
    char inf[20],res[20], ch;
    int i,l = 0, ri = 0;
    cout<< "Enter expression: \n";
    cin>> inf;

    while(inf[l]!='\0')
    {
        l++;
    }

    for(i=0 ; i<l ; i++)
    {
        ch = inf[i];
        if(ch == '(')
        {
            s1.push(ch);
        }
        else if(ch == ')')
        {
            while(head->data!='(')
            {
                res[ri] = head->data;
                ri++;
                s1.pop();
            }
            s1.pop();
        }
        else if(ch == '*' || ch == '/')
        {
            if(head!=NULL)
            {
            while(head->data=='/' || head->data=='*')
            {
                res[ri] = head->data;
                ri++;
                s1.pop();
                if(head==NULL)
                {
                    break;
                }
            }
            }
            s1.push(ch);
        }
        else if(ch == '+' || ch == '-')
        {
            if(head!=NULL)
            {
                while(head->data == '/' || head->data == '*')
                {
                res[ri] = head->data;
                ri++;
                s1.pop();
                if(head==NULL)
                {
                    break;
                }
                }
            }
            s1.push(ch);
        }
        else
        {
            res[ri] = ch;
            ri++;
        }

    }
    if(head!=NULL)
    {
        while(head!=NULL)
        {
            if(head->data!='(')
            {
                res[ri] = head->data;
                ri++;
            }
            s1.pop();
        }
    }
    cout<< "\n\nPostfix: "<< res<< endl;
}

void stacklinklist::infixToPrefix()
{
    char inf[20],res[20], ch;
    int i,l = 0, ri = 0,c;
    cout<< "Enter expression: \n";
    cin>> inf;

    while(inf[l]!='\0')
    {
        l++;
    }

    for(i=0 ; i<l ; i++)
    {
        ch = inf[i];
        if(ch == '(')
        {
            s1.push(ch);
        }
        else if(ch == ')')
        {
            while(head->data!='(')
            {
                res[ri] = head->data;
                ri++;
                s1.pop();
            }
            s1.pop();
        }
        else if(ch == '*' || ch == '/')
        {
            if(head!=NULL)
            {
            while(head->data=='/' || head->data=='*')
            {
                res[ri] = head->data;
                ri++;
                s1.pop();
                if(head==NULL)
                {
                    break;
                }
            }
            }
            s1.push(ch);
        }
        else if(ch == '+' || ch == '-')
        {
            if(head!=NULL)
            {
                while(head->data == '/' || head->data == '*')
                {
                res[ri] = head->data;
                ri++;
                s1.pop();
                if(head==NULL)
                {
                    break;
                }
                }
            }
            s1.push(ch);
        }
        else
        {
            res[ri] = ch;
            ri++;
        }

    }
    if(head!=NULL)
    {
        while(head!=NULL)
        {
            if(head->data!='(')
            {
                res[ri] = head->data;
                ri++;
            }
            s1.pop();
        }
    }
    char pref[20];
    l=0;
    c=0;
    while(res[l]!='\0')
    {
        l++;
    }
    for(i=l-1; i>=0; i--)
    {
        pref[c] = res[i];
        c++;
    }
    cout<< "\n\nPrefix: "<< pref << endl;
}

void stacklinklist::postfixEval()
{
    char posexp[20],ch;
    int l=0, a,b,c;
    cout<< "Enter expression: \n";
    cin>> posexp;
    while(posexp[l]!='\0')
    {
        l++;
    }

    for(int i=0; i<l; i++)
    {
        ch = posexp[i];

        if(ch>= '0' && ch<= '9')
        {
            s1.pushin(ch- '0');
        }
        else
        {
            a = head->intdata;
            s1.pop();
            b = head->intdata;
            s1.pop();

            switch(ch)
            {
            case '+':
                {
                    s1.pushin(a+b);
                    break;
                }
                case '-':
                {
                    s1.pushin(b-a);
                    break;
                }
                case '/':
                {
                    s1.pushin(b/a);
                    break;
                }
                case '*':
                {
                    s1.pushin(a*b);
                    break;
                }
            }

        }
    }
    cout<< "Ans: "<< head->intdata<<endl;
    s1.pop();
}

void stacklinklist::prefixEval()
{
    char preexp[20], posexp[20],ch;
    int l=0,j=0, a,b,c;
    cout<< "Enter expression: \n";
    cin>> preexp;
    while(preexp[l]!='\0')
    {
        l++;
    }

    for(int i = l-1 ; i>=0 ; i-- )
    {
        posexp[j] = preexp[i];
        j++;
    }

    for(int i=0; i<l; i++)
    {
        ch = posexp[i];

        if(ch>= '0' && ch<= '9')
        {
            s1.pushin(ch- '0');
        }
        else
        {
            a = head->intdata;
            s1.pop();
            b = head->intdata;
            s1.pop();

            switch(ch)
            {
            case '+':
                {
                    s1.pushin(a+b);
                    break;
                }
                case '-':
                {
                    s1.pushin(b-a);
                    break;
                }
                case '/':
                {
                    s1.pushin(b/a);
                    break;
                }
                case '*':
                {
                    s1.pushin(a*b);
                    break;
                }
            }

        }
    }
    cout<< "Ans: "<< head->intdata<<endl;
    s1.pop();
}

int main()
{

    int q;
    bool run = true;
    while(run)
    {
        cout << "\n\n1. Push\n2. Pop\n3. Print\n4. Infix to postfix\n5. Infix to prefix\n6. Postfix Evaluation\n7. Prefix Eval\n0. EXIT\n\nEnter choice:\n";
        cin>> q;
        switch(q)
        {
        case 1:
            {
                char a;
                cout<< "Enter data: \n";
                cin>> a;
                s1.push(a);
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
        case 4:
            {
                s1.infixToPostfix();
                break;
            }
        case 5:
            {
                s1.infixToPrefix();
                break;
            }
        case 6:
            {
                s1.postfixEval();
                break;
            }
        case 7:
            {
                s1.prefixEval();
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
