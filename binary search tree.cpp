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

class binarySearchTree
{
private:
    node* root = NULL;
public:
    void insertData(node*, int);
    void display(node*);
    void searchTree(node*,int);
    node* getRoot();
};

node* binarySearchTree::getRoot()
{
    return root;
}

void binarySearchTree::insertData(node* r, int d)
{

    if(root == NULL)
    {
        node* n = new node(d);
        root = n;
        return;
    }

    if(r->data > d)
    {
        if(r->left == NULL)
        {
            node* n = new node(d);
            r->left = n;
            return;
        }

        insertData(r->left,d);
    }
    else
    {
        if(r->right == NULL)
        {
            node* n = new node(d);
            r->right = n;
            return;
        }

        insertData(r->right,d);
    }
}

void binarySearchTree::display(node* n)
{
    if(n==NULL){
        return;
    }
    display(n->left);
    cout<< n->data<< " ";
    display(n->right);
}

void binarySearchTree::searchTree(node* n, int s)
{
    if(n == NULL)
    {
        cout<< "\nNot Found!!\n";
        return;
    }

    if(s == n->data)
    {
        cout<< "\nMatch found!\n";
        return;
    }

    if(s > n->data)
    {
        searchTree(n->right,s);
    }
    else
    {
        searchTree(n->left, s);
    }
}

int main()
{
    binarySearchTree b;
    int d;

    cout<< "\n\nEnter Data: ";
    cin>> d;
    b.insertData(b.getRoot(),d);

    cout<< "\n\nEnter Data: ";
    cin>> d;
    b.insertData(b.getRoot(),d);

    cout<< "\n\nEnter Data: ";
    cin>> d;
    b.insertData(b.getRoot(),d);

    cout<< "\n\nEnter Data: ";
    cin>> d;
    b.insertData(b.getRoot(),d);

    cout<< "\n\nEnter Data: ";
    cin>> d;
    b.insertData(b.getRoot(),d);

    cout<< "\n\nEnter Data: ";
    cin>> d;
    b.insertData(b.getRoot(),d);


    cout<< "\n\nDISPLAY:\n";
    b.display(b.getRoot());

    cout<< "\n\nEnter Data to be searched: ";
    cin>> d;
    b.searchTree(b.getRoot(),d);
    return 0;
}
