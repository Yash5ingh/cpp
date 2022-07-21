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
