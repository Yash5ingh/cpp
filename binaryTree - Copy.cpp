#include<iostream>
using namespace std;

struct node
{
    int data;
    node* right;
    node* left;

    node(int d)
    {
        data = d;
        right = NULL;
        left = NULL;
    }
};

class binaryTree
{
private:
    node* root = NULL;
    char iterate = 'R';
public:

    void createTree();
    void create(node*, int);
    void display(node*);
    node* getRoot();
    void copyTree(node*,node*);
    void insertNode();
    void depthOfTree();
    void leafNodes(node*);
}clone;

void binaryTree::insertNode()
{
    int d;
    char q;
    cout<< "Enter data:\n";
    cin>> d;
    node* n = new node(d);
    node* t = root;
    while(true)
    {
        cout<< "Parent: "<< t->data<< "\nl-Left\nr-Right\n";
        cin >>q;
        if(q == 'l' || q=='L')
        {
            if(t->left == NULL)
            {
                t->left = n ;
                return;
            }
            t = t->left;
        }
        if(q == 'r' || q=='R')
        {
            if(t->right == NULL)
            {
                t->right = n ;
                return;
            }
            t = t->right;
        }
    }
}

node* binaryTree::getRoot()
{
    return root;
}

void binaryTree::createTree()
{
    int data;
    cout<< "ROOT NODE \n";
    cout<< "Enter data:\n";
    cin>> data;
    node* n = new node(data);
    root = n;

    iterate = 'L';
    create(n, n->data);
    iterate = 'R';
    create(n, n->data);
}

void binaryTree::create(node* p, int parent)
{
    char ques;
    int data;

    cout<< "\nparent node: "<< parent<<endl;
    cout<< "Do you want to add "<< iterate <<" node? \n(y/n)\n";
    cin>> ques;

    if(ques=='n'||ques=='N')
    {
        return;
    }

    cout<< "Enter data:\n";
    cin>> data;
    node* n = new node(data);
    if(iterate == 'L')
    {
        p->left = n;
    }
    if(iterate == 'R')
    {
        p->right = n;
    }


    iterate = 'L';
    create(n, n->data);
    iterate = 'R';
    create(n, n->data);
}

void binaryTree::display(node* n)
{
    if(n == NULL)
    {
        return;
    }
    cout<< n->data<< ", ";

    display(n->left);
    display(n->right);
}

void copynodes(node* c,node* n)
{
    if(n == NULL)
    {
        return;
    }

    if(n->left!=NULL)
    {
        node* l = new node(n->left->data);
        c->left = l;
        copynodes(c->left, n->left);
    }

    if(n->right!=NULL)
    {
        node* r = new node(n->right->data);
        c->right = r;
        copynodes(c->right, n->right);
    }
}

void binaryTree::copyTree(node* c,node* n)
{
    if(n == NULL)
    {
        c = NULL;
        return;
    }

    node* q = new node(n->data);
    clone.root = q;
    c=q;

    if(n->left!=NULL)
    {
        node* l = new node(n->left->data);
        c->left = l;
        copynodes(c->left, n->left);
    }

    if(n->right!=NULL)
    {
        node* r = new node(n->right->data);
        c->right = r;
        copynodes(c->right, n->right);
    }
}

int countDepth(node* n, int d)
{
    int l,r;
    if(n==NULL)
    {
        return d-1;
    }

    l=countDepth(n->left,d+1);
    r=countDepth(n->right,d+1);

    d = (l>r) ? l : r;
    return d;
}

void binaryTree::depthOfTree()
{
    int d=0;

    d = countDepth(root,d);

    cout<<"Depth = "<< d;
}

void binaryTree::leafNodes(node* n)
{
    if(n==NULL)
    {
        return;
    }
    if(n->left == NULL && n->right==NULL)
    {
        cout<< n->data << ", ";
        return;
    }

    leafNodes(n->left);
    leafNodes(n->right);
}

int main()
{
    binaryTree b;

    b.createTree();

    cout<< "\n\nBINARY TREE:\n";
    b.display(b.getRoot());
    cout<< "\b\b.";


    b.copyTree(clone.getRoot(),b.getRoot());

    cout<< "\n\nCLONE:\n";
    clone.display(clone.getRoot());
    cout<< "\b\b.";

    //cout<< "\n\nINSERT\n\n";
    //b.insertNode();

    cout<< "\n\nBINARY TREE:\n";
    b.display(b.getRoot());
    cout<< "\b\b.";

    cout<< "\n\n";
    b.depthOfTree();

    cout<< "\n\nLEAF NODES:\n";
    b.leafNodes(b.getRoot());
    cout<< "\b\b.";

    return 0;
}
