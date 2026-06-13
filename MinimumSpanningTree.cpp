#include<iostream>
using namespace std;

class AM
{
    int v,e;
    string city[10];
    int fuel ,total=0;
    int adj[10][10];
    int parent[10];
    int key[10];
    bool visited[10];

    public:
    void create();
    void display();
    void MST();
    void Mindisplay();
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

void AM :: MST()
{
    

    for(int i=0;i<v;i++)
    {
        key[i]=999;
        visited[i]=false;
    }
    key[0]=0;
    parent[0]=-1;

    for(int c=0;c<v-1;c++)
    {
        int min=999;
        int index;
        for(int u=0;u<v;u++)
        {
            if(!visited[u] && key[u]<min)
            {
                min=key[u];
                index=u;
            }
        }

        visited[index]=true;
        for(int i=0;i<v;i++)
        {
            if(adj[index][i]!=0 && !visited[i] && adj[index][i]<key[i])
            {
                key[i]=adj[index][i];
                parent[i]=index;
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


void AM :: Mindisplay()
{
    for(int i=1;i<v;i++)
    {
       cout<<"\n";
        cout<<"Edges are: "<<city[parent[i]]<<"->"<<city[i]<<endl;
        cout<<"Fuel is: "<<adj[parent[i]][i]<<endl;
        total+=adj[parent[i]][i];
    }
    cout<<"Total weight of minimum spanning tree is : "<<total<<endl;
}

int main()
{
    AM a;
    a.create();
    a.display();
    a.MST();
    a.Mindisplay();

    return 0;
}