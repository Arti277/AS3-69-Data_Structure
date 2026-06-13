#include<iostream>
using namespace std;

int D[100];

class Heap{
    int key[100];
    int value;
    int cnt;

    public :
    void create();
    void insert(int val);
    void display();
    void del();
}H[100];  




void Heap:: insert(int val){
    cnt++;
    key[cnt]=val;
    int i=cnt;

    while(i>1){
        int parent=i/2;
        if(key[parent]<key[i]){
            int temp=key[parent];
            key[parent]=key[i];
            key[i]=temp;
            i=parent;
        }
        else{
            break;
        }
    }

}   
void Heap::create(){
    cnt=0;
    int val;
    cout<<"Enter the Total Number of keys ;-\n ";
    int n;
    cin>>n;
    cout<<"Enter the keys\n";
    for(int j=0;j<n;j++){
        cin>>val;
        insert(val);
    }
}

void Heap ::display(){
    for(int i=1;i<=cnt;i++){
        cout<<key[i]<<"\t";
    }
}

int value;
int j=1;
void Heap::del(){
    int loc,i=1;
    D[j]=key[i];
    
    j+=1;
    int temp=key[i];
    cout<<temp<<" Deleted \n";
    key[i]=key[cnt];
    cnt--;

    while((2*i)<=cnt){
        int LC=2*i;
        int RC=2*i+1;

        if(key[LC]>key[RC]){
             value=key[LC];
            loc=LC;
        }
        else{
            value=key[RC];
            loc=RC;
        }

        if(key[i]<value){
            temp=key[i];
            key[i]=value;
            key[loc]=temp;
            i=loc;
        }
        else{
            return;
        }
    }
    


}

int main(){

    Heap h;

    int ch,c=1;

    do{
        cout<<"\nEnter your choice :-  \n";
        cout<<"1.Create\n 2.Insert New Element\n 3.Display\n 4.Delete\n 5.Exit\n";
        cin>>ch;

        switch(ch){
        
            case 1: h.create();
                    break;

            case 2:{
                int v;
                cout<<"\nEnter the value u want to insert :-\n";
                cin>>v;
                h.insert(v);
                break;
            }

            case 3: h.display();
                    break;

            case 4: h.del();
                    break;
                    
            case 5 :
                    cout<<"\nExiting...\n";
                    c=0;
                    break;

        }

    }while(c==1);

    }