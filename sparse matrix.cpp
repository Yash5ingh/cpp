#include<iostream>
using namespace std;

const int MAX=20;
class SparseMatrix
{
    public:
        int mat[MAX][MAX],smat[MAX][3];
        int row,col,t,i,j,counter;

        void readMatrix();
        void displayMatrix();
        void sparseMatrixRepresentation();
        void displaySparse();
        void additionSparse();
        void transposeSparse();
}m[3];

void SparseMatrix::readMatrix()
{
    cout<< "Enter number of rows: \n";
    cin>> row;
    cout<< "Enter number of columns: \n";
    cin>> col;

    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            cout<< "Enter element at R="<< i+1<< " C="<< j+1<< endl;
            cin>> mat[i][j];
        }
    }
}

void SparseMatrix::displayMatrix()
{
    cout<< endl<<endl<<"------------MATRIX------------\n\n\n";
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            cout<<"\t"<< mat[i][j];
        }
        cout<< endl<<endl;
    }
    cout<<"\n------------------------------\n\n";
}

void SparseMatrix::sparseMatrixRepresentation()
{
    t=0;
    counter=0;

    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(mat[i][j]!= 0)
            {
                counter++;
                t++;
                smat[t][0]=i;
                smat[t][1]=j;
                smat[t][2]=mat[i][j];
            }
        }
    }
    smat[0][0]=row;
    smat[0][1]=col;
    smat[0][2]=counter;
}

void SparseMatrix::displaySparse()
{
    cout<< endl<<endl<<"--------------SPARSE MATRIX-------------\n\n\n";
    cout<< "ROW\t|\tCOL\t|\tVALUE\t\n";
    cout<<"--------|---------------|---------------\n";
    for(i=0; i<=t; i++)
    {
        for(j=0; j<3; j++)
        {
            if(j==2)
            {
                cout<<smat[i][j]<<"\t\t";
            }
            else
            {
                cout<<smat[i][j]<<"\t|\t";
            }
        }
        cout<<"\b\b\b";
        cout<< endl;
    }
    cout<<"\n-----------------------------------------\n\n";
}

void SparseMatrix::additionSparse()
{
    int c0=1,c1=1;
    counter=0;
    t=0;
    if(m[0].row==m[1].row && m[0].col==m[1].col)
    {
       while(c0 <= m[0].t && c1 <= m[1].t)
       {

           if(m[0].smat[c0][0] == m[1].smat[c1][0] && m[0].smat[c0][1] == m[1].smat[c1][1])
                {
                    t++;
                    smat[t][0]=m[0].smat[c0][0];
                    smat[t][1]=m[0].smat[c0][1];
                    smat[t][2]=m[0].smat[c0][2]+m[1].smat[c1][2];
                    c0++;
                    c1++;
                }

            else if(m[0].smat[c0][0] != m[1].smat[c1][0])
                {
                    t++;
                    if(m[0].smat[c0][0] < m[1].smat[c1][0])
                    {
                        smat[t][0]=m[0].smat[c0][0];
                        smat[t][1]=m[0].smat[c0][1];
                        smat[t][2]=m[0].smat[c0][2];
                        c0++;
                    }
                    else
                    {
                        smat[t][0]=m[1].smat[c1][0];
                        smat[t][1]=m[1].smat[c1][1];
                        smat[t][2]=m[1].smat[c1][2];
                        c1++;
                    }

                }

            else if(m[0].smat[c0][1] != m[1].smat[c1][1])
                {
                    t++;
                    if(m[0].smat[c0][1] < m[1].smat[c1][1])
                    {
                        smat[t][0]=m[0].smat[c0][0];
                        smat[t][1]=m[0].smat[c0][1];
                        smat[t][2]=m[0].smat[c0][2];
                        c0++;
                    }
                    else
                    {
                        smat[t][0]=m[1].smat[c1][0];
                        smat[t][1]=m[1].smat[c1][1];
                        smat[t][2]=m[1].smat[c1][2];
                        c1++;
                    }

                }
       }

           while(c1 <= m[1].t)
           {
               t++;
                smat[t][0]=m[1].smat[c1][0];
                smat[t][1]=m[1].smat[c1][1];
                smat[t][2]=m[1].smat[c1][2];
                c1++;

           }
           while(c0 <= m[0].t)
           {
               t++;
                smat[t][0]=m[0].smat[c0][0];
                smat[t][1]=m[0].smat[c0][1];
                smat[t][2]=m[0].smat[c0][2];
                c0++;
           }


        smat[0][0]=m[0].row;
        smat[0][1]=m[0].col;
        smat[0][2]=t;
        m[2].displaySparse();
    }

    else
    {
        cout<< "\nAddition not possible!!\n";
    }
}

void SparseMatrix::transposeSparse()
{
    int temp=0;
    for(int i=0; i<=t ; i++)
    {
        temp = smat[i][0];
        smat[i][0]= smat[i][1];
        smat[i][1]= temp;
    }

    for(i=1 ; i< t; i++)
    {
        if(smat[i][0]>smat[i+1][0])
        {
            temp = smat[i][0];
            smat[i][0]= smat[i+1][0];
            smat[i+1][0]= temp;

            temp = smat[i][1];
            smat[i][1]= smat[i+1][1];
            smat[i+1][1]= temp;

            temp = smat[i][2];
            smat[i][2]= smat[i+1][2];
            smat[i+1][2]= temp;
            i = 1;
        }
    }
}



int main()
{
    cout<< "\n\nMatrix 1: \n";
    m[0].readMatrix();
    m[0].displayMatrix();
    m[0].sparseMatrixRepresentation();
    m[0].displaySparse();
    m[0].transposeSparse();
    m[0].displaySparse();
    cout<< "\n\nMatrix 2: \n";
    m[1].readMatrix();
    m[1].displayMatrix();
    m[1].sparseMatrixRepresentation();
    m[1].displaySparse();
    cout<< "\n\nadding 1 and 2\n";
    m[2].additionSparse();

    return 0;
}
