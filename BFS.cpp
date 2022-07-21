#include<iostream>
#include<queue>
#include<stack>
using namespace std;
const int Max = 20;


int searchIn(int a[], int s, int m)
{
    for(int i = 0; i<m; i++)
    {
        if(a[i]==s)
        {
            return i;
        }
    }
    return -1;
}

class graph
{
public:
    int noOfEdges;
    int noOfVertices;
    int adjMatrix[Max][Max];

    graph()
    {
        cout<< "Enter no of vertices: \n";
        cin>>noOfVertices;
        cout<< "Enter no of Edges: \n";
        cin>>noOfEdges;
    }

    void createMatrix();
    void bfs();
    void dfs();
}j;

void graph::createMatrix()
{
    for(int i = 0; i<noOfVertices; i++)
    {
        for(int j=0; j<noOfVertices; j++)
        {
            adjMatrix[i][j]= 0;
        }
    }

    int v1,v2;
    for(int i = 0; i< noOfEdges ; i++)
    {
        cout<< "\n\nEnter Edge "<< i+1<< ": \n";
        cin>> v1>> v2;
        adjMatrix[v1][v2]=1;
        adjMatrix[v2][v1]=1;
    }


    cout<< "\n\n";
    for(int i = 0; i<noOfVertices; i++)
    {
        for(int j=0; j<noOfVertices; j++)
        {
            cout<< adjMatrix[i][j]<< "  ";
        }
        cout<< "\n";
    }
}

void graph::bfs()
{
    int result[noOfVertices];
    for(int i = 0; i<noOfVertices; i++)
    {
        result[i]= -1;
    }
    int visited = 0;
    int current = 0;
    queue<int> q;
    q.push(current);

    while(visited < noOfVertices)
    {
        for(int i=0; i<noOfVertices; i++)
        {
            if(adjMatrix[current][i]== 1)
            {
                if(searchIn(result, i, noOfVertices) == -1)
                {
                    q.push(i);
                }
            }
        }
         if(searchIn(result, current, noOfVertices) == -1)
            {
                result[visited] = current;
                visited++;
            }
        q.pop();
        current = q.front();

    }

    cout<< "\n\n ---BFS---\n";
    for(int i =0 ; i<noOfVertices; i++)
    {
        cout<< result[i]<< ",";
    }
    cout<< "\b ";
    cout<< "\n\n";
}

void graph::dfs()
{
    int result[noOfVertices];
    for(int i = 0; i<noOfVertices; i++)
    {
        result[i]= -1;
    }

    int visited = 0;
    int pre;
    int current = 0;
    stack<int> s;

    while(visited < noOfVertices)
    {
        if(searchIn(result, current, noOfVertices) == -1)
        {
            result[visited] = current;
            visited++;
        }
        pre = current;
        for(int i = 0; i<noOfVertices; i++)
        {
            if(adjMatrix[current][i]==1)
            {
                if(searchIn(result, i, noOfVertices) == -1)
                {
                    s.push(current);
                    current = i;
                    break;
                }
            }
        }
        if(current == pre)
            {
                current = s.top();
                s.pop();
            }
    }
    cout<< "\n\n ---DFS---\n";
    for(int i =0 ; i<noOfVertices; i++)
    {
        cout<< result[i]<< ",";
    }
    cout<< "\b ";
    cout<< "\n\n";
}

int main()
{
    j.createMatrix();
    j.bfs();
    j.dfs();
    return 0;
}
