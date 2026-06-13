#include<iostream>
using namespace std;


class Heap{
    int key[100];
    int value;
    int count=0;

    public :
    void create();
    void insert(int val);
    void display();
    
}H[100];




void Heap:: insert(int val){
    count++;
    key[count]=val;
    int i=count;

    while(i>1){
        int parent=i/2;
        if(key[parent]>key[i]){
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
    count=0;
    int val;
    cout<<"Enter the Total Number of keys :-\n ";
    int n;
    cin>>n;
    cout<<"Enter the keys\n";
    for(int j=0;j<n;j++){
        cin>>val;
        insert(val);
    }
}

void Heap ::display(){
    for(int i=1;i<=count;i++){
        cout<<key[i]<<"\t";
    }
}

int main(){

    Heap h;

    int ch,c=1;

    do{
        cout<<"Enter your choice :-  \n";
        cout<<"1.Create\n 2.Insert New Element\n 3.Display\n 4.Exit\n";
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
            
            case 4 :
                    cout<<"\nExiting...\n";
                    c=0;
                    break;

        }

    }while(c==1);

    }