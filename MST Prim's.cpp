#include<iostream>
using namespace std;
const int Max = 20;

int mini(int a[], int n)
{
    int m =999;
    int x;

    for(int i = 0; i<n ; i++)
    {
        if(a[i]<m && a[i]>0)
        {
            m = a[i];
            x = i;
        }
    }
    return x;
}

int disjoint(int parent[],int a,int b)
{
    if(parent[a] == parent[b])
    {
        return 0;
    }
    return 1;
}

void updateParents(int parent[],int a,int b,int n)
{
    int k = parent[b];

    for(int i=0; i<n ; i++ )
    {
        if( parent[i] == k)
        {
            parent[i]= parent[a];
        }
    }
}

class graph
{
public:
    int e;
    int v;
    int adjMatrix[Max][Max];

    graph()
    {
        cout<< "Enter no of vertices: \n";
        cin>>v;
        cout<< "Enter no of Edges: \n";
        cin>>e;
    }

    void createMatrix();
    void prims();
}j;

void graph::createMatrix()
{
    for(int i = 0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            adjMatrix[i][j]= 0;
        }
    }

    int v1,v2,w;
    for(int i = 0; i< e ; i++)
    {
        cout<< "\nEnter S D W ("<< i+1<< "):\n";
        cin>> v1>> v2>> w;
        adjMatrix[v1][v2]=w;
        adjMatrix[v2][v1]=w;
    }


    cout<< "\n\n ---GRAPH---\n";
    for(int i = 0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            cout<< adjMatrix[i][j]<< "  ";
        }
        cout<< "\n";
    }
}

void graph::prims()
{
    int MST[v][v];
    int added = 0;
    int parent[v];
    int visited[v];
    int key[v];

    for(int i = 0; i<v ; i++)
    {
        parent[i] = i;
        visited[i] = 0;
        key[i] = 999;
        for(int j = 0 ; j< v; j++)
        {
            MST[i][j] = 0;
        }
    }

    visited[0] = 1;
    key[0] = 0;

    while(added < v-1)
    {
        for(int i = 0; i<v; i++)
        {
            if(visited[i])
            {
            for(int j = 0; j<v ; j++)
            {
                    if(adjMatrix[i][j]!=0 && !visited[j] && key[j]>adjMatrix[i][j])
                    {
                        key[j] = adjMatrix[i][j];
                    }
                }
            }
        }

        int u = mini(key, v);

        for(int i = 0; i<v; i++)
        {
            for(int j = 0; j<v ; j++)
            {
                if(adjMatrix[i][j]==key[u] && disjoint(parent,i, j))
                {
                    added++;
                    key[i] = 0;
                    key[j] = 0;
                    visited[i] = 1;
                    visited[j] = 1;
                    updateParents(parent,i,j,v);
                    MST[j][i] = adjMatrix[j][i];
                    MST[i][j] = adjMatrix[i][j];
                    i = v;
                    j = v;
                }
            }
        }

    }
        cout<< "\n\n---MST---\n";
        for(int i = 0; i<v; i++)
        {
            for(int j = 0; j<v ; j++)
            {
                cout<< MST[i][j]<<" ";
            }
            cout<< endl;
        }
        cout<< "\n\n";
}

int main()
{
    j.createMatrix();
    j.prims();

    return 0;
}
