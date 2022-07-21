#include<iostream>
#include<vector>
using namespace std;

int order;

struct node
{
    int data;
    vector<node*> next;

    node()
    {
        for(int i = 0; i<order ; i++)
        {
            next.push_back(NULL);
        }
    }
};

class tree
{
public:
    tree()
    {
        cout<< "Enter order of the tree: \n";
        cin>>order;
    }
    node* root=NULL;

    void addBranch();
    void print();
    void searchTree();
    void deleteNode();
};

void tree::addBranch()
{
    if(root==NULL)
    {
        node* n = new node;
        cout<< "Enter data: \n";
        cin>> n->data;
        root = n;
        return;
    }
    else
    {
        node*temp = root;
        int d,p=0;
        while(true)
        {
            cout<< "Enter path from root: \n";
            cin>> p;
            if(temp->next[p] == NULL)
            {
                node* n = new node;
                cout<< "Enter data : \n";
                cin>> n->data;
                temp->next[p] = n;
                return;
            }
            temp = temp->next[p];
        }
    }
}

void printr(node*temp)
{
    if(temp == NULL)
    {
        return;
    }
    cout<<temp->data<<"-->";

    for(int i = 0; i<order; i++)
    {
        printr(temp->next[i]);
    }
}

void tree::print()
{
    node* temp = root;
    if(temp == NULL)
    {
        return;
    }
    cout<<temp->data<<"-->";

    for(int i = 0; i<order; i++)
    {
        printr(temp->next[i]);
    }
}

int main()
{
    tree t;
    t.addBranch();
    t.addBranch();
    t.addBranch();
    t.addBranch();
    t.addBranch();
    t.addBranch();
    t.addBranch();
    t.addBranch();
    t.addBranch();
    t.addBranch();

    t.print();
    return 0;
}
