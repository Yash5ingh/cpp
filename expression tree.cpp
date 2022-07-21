#include<iostream>
using namespace std;


struct node
{
    char data;
    node* right;
    node* left;

    node(char d)
    {
        data = d;
        right = NULL;
        left = NULL;
    }
};

class expressionTree
{
private:
    node* root = NULL;
    char iterate = 'R';
public:
    void create();
    void inorder(node*);
    void preorder(node*);
    void postorder(node*);
    void evaluate();
    node* getRoot();
};

struct stak
{
    node* data;
    stak* next;
};

class Stack
{
public:
    stak* top = NULL;

    void push(node*);
    void pop();
    node* getTop();
};

void Stack::push(node* a)
{
    stak* n = new stak;
    n->next = NULL;
    n->data = a;
    if(top!=NULL)
    {
        n->next = top;
        top = n;
    }
    else
    {
        top = n;
    }
}

void Stack::pop()
{
    stak* temp;
    temp = top;
    top = top->next;
    temp = NULL;
    delete temp;
}

node* Stack::getTop()
{
    return top->data;
}

void expressionTree::create()
{
    char exp[20];
    char e;
    int i =0;
    Stack a;

    cout<< "Enter Postfix Expression:\n";
    cin>> exp;

    do
    {
        e = exp[i];

        node*n = new node(e);

        if(e == '+' ||e == '*' ||e == '/' ||e == '-')
        {
            root = n;

            n->left = a.getTop();
            a.pop();
            n->right = a.getTop();
            a.pop();

            a.push(n);
        }
        else
        {
            a.push(n);
        }
        i++;
    }while(e!= '\0');
}

node* expressionTree::getRoot()
{
    return root;
}

void expressionTree::inorder(node* n)
{
    if(n==NULL){
        return;
    }
    inorder(n->left);
    cout<< n->data<< " ";
    inorder(n->right);
}

void expressionTree::postorder(node* n)
{
    if(n==NULL){
        return;
    }
    inorder(n->left);
    inorder(n->right);
    cout<< n->data<< " ";
}

void expressionTree::preorder(node* n)
{
    if(n==NULL){
        return;
    }
    cout<< n->data<< " ";
    inorder(n->left);
    inorder(n->right);
}

int main()
{
    expressionTree t;

    t.create();

    cout<< "\n\nINORDER: ";
    t.inorder(t.getRoot());
    cout<< "\n\n";

    cout<< "\n\nPOSTORDER: ";
    t.postorder(t.getRoot());
    cout<< "\n\n";

    cout<< "\n\nPREORDER: ";
    t.preorder(t.getRoot());
    cout<< "\n\n";

    return 0;
}
