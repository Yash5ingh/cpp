#include<iostream>
#include<fstream>
using namespace std;

class files
{
private:
    char str[20];
    string read;
    fstream l;
public:

    void display();
    void add();
    void searchRec();
    void modify();
    void deleteRec();
    void format();
}j;

void files::format()
{
    fstream tem;
    l.open("C:\\cllg\\data.txt",ios::in);
    tem.open("C:\\cllg\\temp.txt",ios::out);
    if(!l)
    {
        cout<< "\nFILE NOT FOUND!";
        return;
    }
    while(!l.eof())
    {
        getline(l,read);
        if(read[0]==NULL)
        {
            break;
        }
        tem<<read<<"\n";
    }
    tem.close();
    l.close();
    remove("C:\\cllg\\data.txt");
    rename("C:\\cllg\\temp.txt","C:\\cllg\\data.txt");
}

void files::add()
{
    char name[10]="o",age[5],job[10];
    l.open("C:\\cllg\\data.txt",ios::app);
    if(!l)
    {
        cout<< "FILE NOT FOUND!";
        return;
    }
    cout<< "Enter name age and job of employee:\n";
    cin>> name;
    cin>> age;
    cin>> job;

    l<< name <<"\t" <<age <<"\t" <<job<<"\n";
    l.close();
}

void files::display()
{
    int i=0;
    l.open("C:\\cllg\\data.txt",ios::in);
    if(!l)
    {
        cout<< "\nFILE NOT FOUND!";
        return;
    }
    cout<< "\n\n#\tNAME\tAGE\tJOB\n";
    while(!l.eof())
    {
        i++;
        getline(l,read);
        if(read[0]==NULL)
        {
            break;
        }
        cout<<i<<"\t"<<read<< endl;
    }
    l.close();
}

void files::searchRec()
{
    char ser[30];
    cout<< "\n\nEnter stat to be searched: \n";
    cin>>ser;
    l.open("C:\\cllg\\data.txt",ios::in);
    while(!l.eof())
    {
        getline(l,read);
        if(read.find(ser,0)!=string::npos)
        {
            cout<< read<<endl;
        }
    }
    l.close();
}

void files::modify()
{
    char name[10]="o",age[5],job[10];
    fstream tem;
    int i=0,target;
    l.open("C:\\cllg\\data.txt",ios::in);
    tem.open("C:\\cllg\\temp.txt",ios::out);
    cout<< "\n\nEnter # to be modified: \n";
    cin>>target;
    while(!l.eof())
    {
        i++;
        getline(l,read);

        if(i==target)
        {
            cout<< "Enter name age and job of employee:\n";
            cin>> name;
            cin>> age;
            cin>> job;
            tem<< name <<"\t" <<age <<"\t" <<job<<"\n";
        }
        else
        {
            tem<<read<<"\n";
        }
    }
    tem.close();
    l.close();
    remove("C:\\cllg\\data.txt");
    rename("C:\\cllg\\temp.txt","C:\\cllg\\data.txt");
}

void files::deleteRec()
{
    fstream tem;
    int i=0,target;
    l.open("C:\\cllg\\data.txt",ios::in);
    tem.open("C:\\cllg\\temp.txt",ios::out);
    cout<< "\n\nEnter # to be deleted: \n";
    cin>>target;
    while(!l.eof())
    {
        i++;
        getline(l,read);
        if(i==target)
        {
            continue;
        }
        else
        {
            tem<<read<<"\n";
        }
    }
    tem.close();
    l.close();
    remove("C:\\cllg\\data.txt");
    rename("C:\\cllg\\temp.txt","C:\\cllg\\data.txt");
}

int main()
{
    int ch;

    do
    {
        j.format();
        cout<<"\n\n1) Add"<<endl;
        cout<<"2) Display"<<endl;
        cout<<"3) Modify"<<endl;
        cout<<"4) Search"<<endl;
        cout<<"5) Delete"<<endl;
        cout<<"0) Exit"<<endl;
        cout<<"Enter your choice:\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                {
                    j.add();
                    break;
                }


            case 2:
                {
                    j.display();
                    break;
                }

            case 3:
                {
                    j.modify();
                    break;
                }
            case 4:
                {
                    j.searchRec();
                    break;
                }
            case 5:
                {
                    j.deleteRec();
                    break;
                }
            case 0:
                {
                    cout<<"\n\nExit"<<endl;
                    break;
                }
            default:
                {
                    cout<< "Invalid choice";
                }
      }
   }while(ch!=0);

    return 0;
}
