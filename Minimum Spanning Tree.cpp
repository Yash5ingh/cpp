#include<iostream>
#include<vector>
using namespace std;

struct edge
{
    int source, destination , weight;
};

void dispEdges(edge ed[], int n)
{
    cout<< "\nS D W\n";
    for(int i=0; i<n; i++)
    {
        cout<< ed[i].source << " " << ed[i].destination << " " << ed[i].weight<< endl;
    }
    cout<< "\n\n";
}

void sortWeight(edge ed[], int n)
{
    int m,t;
    for(int i=0; i<n; i++)
    {
        m = i;
        for(int j=i ; j<n; j++)
        {
            if(ed[j].weight<ed[m].weight)
            {
                m = j;
            }
        }
        if(m!=i)
        {
            t = ed[m].weight ;
            ed[m].weight = ed[i].weight;
            ed[i].weight = t;

            t = ed[m].source ;
            ed[m].source = ed[i].source;
            ed[i].source = t;

            t = ed[m].destination ;
            ed[m].destination = ed[i].destination;
            ed[i].destination = t;

        }
    }
}

void joinParent(int parent[], int v, int s, int d)
{
    int k = parent[d];
    for(int i = 0 ; i<v; i++)
    {
        if(parent[i] == k)
        {
            parent[i] = parent[s];
        }
    }
}

void kruskalsAlgo(edge ed[],int e,int v)
{
    edge MST[v-1];
    int added= 0,j=0;
    edge curr;
    int parent[v];
    for(int i =0 ; i<v; i++)
    {
        parent[i] = i;
    }

    while(added < v-1)
    {
        curr = ed[j];
        if(parent[curr.source] != parent[curr.destination])
        {
            joinParent(parent, v, curr.source, curr.destination);

            MST[added] = curr;
            added++;
        }
        j++;
    }
    cout<< "\n\n---MST---\n";
    dispEdges(MST,v-1);
}

int main()
{
    int e,v;
    cout<< "Enter no of edges:\n";
    cin>> e;
    cout<< "Enter no of vertices:\n";
    cin>> v;

    edge edges[e];

    for(int i= 0; i<e; i++)
    {
        cout<< "Enter source destination weight of edge "<< i+1<< ": \n";
        cin>> edges[i].source >> edges[i].destination>> edges[i].weight;
    }
    cout<< "---GRAPH---";
    dispEdges(edges,e);

    sortWeight(edges,e);
    kruskalsAlgo(edges,e,v);

    return 0;
}
