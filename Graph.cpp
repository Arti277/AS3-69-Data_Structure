#include<iostream>
using namespace std;

class AM
{
    int v,e;
    string city[10];
    int fuel;
    int adj[10][10];

    public:
    void create();
    void display();
};

void AM::create()
{
    cout<<"Enter the no of cities:\n";
    cin>>v;
    cout<<"Enter the name of cities\n";
    for(int i=0;i<v;i++)
    {
     cin>>city[i];
    }

    cout<<"Enter the weight for source and destination city\n";
    for(int i=0;i<v;i++)
    {
        for(int j=i;j<v;j++)
        {
            if(i!=j)
            {
                cout<<"Enter fuel to source city "<<city[i]<<" to destination city: "<<city[j]<<endl;
                cin>>fuel;
                adj[i][j]=fuel;
                adj[j][i]=fuel;

                
            }
            else{
                adj[i][j]=0;
                
            
            }
        }


    }
}

void AM :: display()
{
    cout<<"\t";
    for(int i=0;i<v;i++)
    {
        cout<<city[i]<<"\t";
    }
    for(int i=0;i<v;i++)
    {
        cout<<"\n"<<city[i];
        for(int j=0;j<v;j++)
        {
            cout<<"\t"<<adj[i][j];
        }
    }
}

int main()
{
    AM a;
    a.create();
    cout<<"**************************"<<endl;
    a.display();
    return 0;
}