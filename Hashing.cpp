#include<iostream>
using namespace std;

int key[100];
int chain[100];

class Hash
{
    int prn,per,rno;
    string name,add;

    public:
    void declareTable();

    void display();
    void insert();
    void search();
    void Delete();
    void modify();

}H[100];

void Hash :: declareTable()
{
int n;
        cout<<"Enter the no. of student whose info you want to store : \n";
        cin>>n;
        cout<<"Enter the prn of those student: \n";
        for(int i=0;i<n;i++)
        {
            cin>>key[i];
        }

        for(int i=0;i<10;i++)
        {
            H[i].prn=-1;
            chain[i]=-2;
        }

}

void Hash :: display()
{
    cout<<"\nLoc\tprn\tname\tadd\tper\tchain";
    for(int i=0;i<10;i++)
    {
        cout<<"\n"<<i<<"\t"<<H[i].prn<<"\t"<<H[i].name<<"\t"<<H[i].add<<"\t"<<H[i].per<<"\t"<<chain[i];
    }
}

void Hash :: insert()
{
    int loc,pos;
    for(int i=0;i<10;i++)
    {
    loc=key[i]%10;
    pos=loc;
    do{
       
        if(H[loc].prn==-1)
        {
            H[loc].prn=key[i];
            cout<<"\nEnter the name add percentage of the student\n";
            cin>>H[loc].name>>H[loc].add>>H[loc].per;

           
            break;
        }
        else{
            
            loc=(loc+1)%10;
            if(chain[pos]==-2)
            {
               chain[pos]=loc;
            }
            else{
                pos=chain[pos];
            }
        }
    }while(loc<10);
    }
}

int main()
{
    Hash h;
    h.declareTable();
     h.display();
     h.insert();
    h.display();
    
    return 0;
}