#include<iostream>
using namespace std;

int key[100];
int chain[100];
 int n;

class Hash{
    int prn,per;
    string name,add;

    public :
    void declareTable();
    void insert();
    void display();
    void search(int p,int l);
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
        chain[i]=-2;
    }

}

void Hash::insert(){

    int loc,pos,temp=0;
    for(int i=0;i<n;i++){
        loc=key[i]%10;
        pos=loc;
            
        do{
            if(H[loc].prn==-1){
                H[loc].prn=key[i];
                cout<<"\nEnter the name , percentage and address of roll no "<<key[i]<<" :- \n";
                cin>>H[loc].name>>H[loc].per>>H[loc].add;
                if(pos!=loc){
                chain[pos]=loc;
                }
                break; 
            }
            else{
                
                loc=(loc+1)%10;
                if(chain[pos]!=-2){
    
                    pos=chain[pos];
                    
                }
            }

       
    }while(loc<10);
}
}

void Hash::del(int p){
        int l=p%10;
        int temp;

        while(l!=-2){
            if(p==H[l].prn){
                cout<<H[l].prn<<" Deleted\n";
                while(chain[l]!=-2){
                    temp=l;
                    H[l].prn=H[chain[l]].prn;
                    H[l].name=H[chain[l]].name;
                    H[l].add=H[chain[l]].add;
                    H[l].per=H[chain[l]].per;
                    l=chain[l];
                }

                H[l].prn=-1;
                 H[l].name=" ";
                  H[l].add="";
                   H[l].per=0;
                if(H[l].prn==-1){
                    chain[temp]=-2;
                }

                return;
            }
            else{
                temp=l;
                l=chain[l];
            }
           
        }

        cout<<"\nNot found\n";
        
}


void Hash::display(){

    cout<<"\nLoc\tprn\tname\tadd\tper\tchain";
    for(int i=0;i<10;i++){
        cout<<"\n"<<i<<"\t"<<H[i].prn<<"\t"<<H[i].name<<"\t"<<H[i].add<<"\t"<<H[i].per<<"\t"<<chain[i];

    }
}
int f=0;
void Hash::search(int p,int l){
    

    if(H[l].prn==p){
        cout<<H[l].prn<<"\t"<<H[l].name<<"\t"<<H[l].add<<"\t"<<H[l].per<<"\n";
        f=1;
       return ;
    }
    else{
        l=chain[l];
        if(l==-2){
            f=0;
            return ;
        }
        search(p,l);
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
                l=p%10;
                h.search(p,l);
                if(f==0){
                    cout<<"No student with prn "<<p<<" found\n";
                }
                break;
            }

            case 4:{
                    int p;
                    cout<<"Enter the prn which u want to delete :-\n ";
                    cin>>p;
                    h.del(p);
                    break;
            }

            case 5: c=0;
                    cout<<"Exiting...";
                break;
        }

    }while(c==1);


    return 0;
}