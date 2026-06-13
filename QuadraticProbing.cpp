#include<iostream>
using namespace std;

int key[100];
 int n;

class Hash{
    int prn,per;
    string name,add;

    public :
    void declareTable();
    void insert();
    void display();
    void search(int p,int l,int q);
    void del(int p);
}H[100];

void Hash :: declareTable(){
   
    cout<<"\nEnter the total number of students :- ";
    cin>>n;
    cout<<"\nEnter the prn numbers of student :- ";
    for(int i=0;i<n;i++){
        cin>>key[i];
    }
    for(int i=0;i<10;i++){
        H[i].prn=-1;
    }

}

void Hash::insert(){

    int loc;
    for(int i=0;i<n;i++){
        int j=1;
        loc=key[i]%10;
        int temp=loc;
        
            
        do{
            if(H[temp].prn==-1){
                H[temp].prn=key[i];
                cout<<"\nEnter the name , percentage and address of roll no "<<key[i]<<" :- \n";
                cin>>H[temp].name>>H[temp].per>>H[temp].add;
                break; 
            }
            else{
                temp=(loc+(j*j))%10;
                j++;
            }

       
    }while(loc<10 && j<10);
}
}
int k=1,count=0,flag=0;
void Hash::del(int p){
        int l=p%10;
        int temp=l;

        while(l!=-2 && count<10){
            if(H[temp].prn==p){
                cout<<"Data of Student with prn "<<H[temp].prn<<" Deleted \n";
                H[temp].prn=-1;
                flag=1;
                return;
            }
            else{
                temp=(l+(k*k))%10;
                k++;
                count ++;
            }
        }      
        
}

void Hash::display(){

    cout<<"\nLoc\tprn\tname\tadd\tper";
    for(int i=0;i<10;i++){
        cout<<"\n"<<i<<"\t"<<H[i].prn<<"\t"<<H[i].name<<"\t"<<H[i].add<<"\t"<<H[i].per<<"\t";

    }
}
int f=0;
int t=1;
void Hash::search(int p,int l,int q){
    
      if(H[l].prn == -1){
            return;
        }

    if(H[l].prn==p){
        cout<<H[l].prn<<"\t"<<H[l].name<<"\t"<<H[l].add<<"\t"<<H[l].per<<"\n";
        f=1;
       return ;
    }
    else{
        l=(q+(t*t))%10;
        t++;
        search(p,l,q);
        return;
        
    }      

}

int main(){
    Hash h;
    int ch,c=1;

    do{
        cout<<"\nEnter Your Choice :- \n";
        cout<<"1.Declare table\n 2.Display\n 3.Search\n 4.Delete\n 5.Exit\n";
        cin>>ch;

        switch(ch){
            case 1:h.declareTable();
                    h.insert();
                    break;
            
            case 2:h.display();
                    break;
            
            case 3:{
                
                int p,l;
                f=0;
                cout<<"Enter the prn u want to search\n";
                cin>>p;
                int q=p%10;
                 l=q;
                h.search(p,l,q);
                if(f==0){
                    cout<<"No student with prn "<<p<<" found\n";
                }
                break;
            }

            case 4:{
                    int p;
                    flag=0;
                    cout<<"Enter the prn which u want to delete :-\n ";
                    cin>>p;
                    h.del(p);
                    if(flag==0){
                        cout<<"Not found";
                    }

                    break;
            }

            case 5: c=0;
                    cout<<"Exiting...";
                break;
        }

    }while(c==1);


    return 0;
}