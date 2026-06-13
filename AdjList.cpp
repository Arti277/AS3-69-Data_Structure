#include<iostream>
using namespace std;

class AL{
    int v,e;
    string city;
    int fuel;
    AL *next,*temp;

    public :
    void create();
    void addedge();
    void display();

}*head[10];

void AL:: create(){
    cout<<"Enter the number of cities :- \n";
    cin>>v;
    cout<<"Enter the Name of cities :-\n";

    for(int i=0;i<v;i++){
        head[i]=new AL;
        cin>>head[i]->city;
        head[i]->next=NULL;
        head[i]->fuel=0;
    }

}

void AL :: addedge(){
    AL *n,*temp;
    string s,d;
    int e,j;

    cout<<"Enter the number of edges :- \n";
    cin>>e;

    for(int i=0;i<2*e;i++){
        cout<<"Enter the source and Destination :-\n";
        cin>>s>>d;

        for(j=0;j<v;j++){
            if(s==head[j]->city)
            {
                break;
            }
        }


    n = new AL;
    n->city=d;

    cout<<"Enter the fuel from Source ("<<s<<") to destination ("<<d<<") :- \n";
    cin>>n->fuel;
    n->next=NULL;

   
    temp=head[j];

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;

    }
}

void AL ::display(){

    for(int i=0;i<v;i++){
        temp=head[i];
        cout<<temp->city<<"->";
        
        while(temp!=NULL){
            cout<<temp->city<<":"<<temp->fuel<<"\n";
            temp=temp->next;
        }
        
    }
}

int main(){
    AL a;

    a.create();
    a.addedge();
    a.display();
    
    return 0;
}