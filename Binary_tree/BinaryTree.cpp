#include<iostream>
using namespace std;

class BT
{
    char data;
    BT *LC,*RC;

    public:
    
        void Create();
        void insert(BT *root,BT *next);
        void display(BT *root);
    
}*root;

void BT::Create()
{
    int c;
    root=new BT;
    root->LC=root->RC=NULL;
    cout<<"ENTER THE DATA INTO THE ROOT NODE"<<endl;
    cin>>root->data;

    BT *next;
    do{
    next=new BT;
    next->LC=next->RC=NULL;
    cout<<"ENTER THE DATA INTO THE NEW NODE"<<endl;
    cin>>next->data;
    insert(root,next);
    cout<<"DO U WANT TO CREATE NEW NODE"<<endl;
    cin>>c;
    }while(c==1);
}

void BT::insert(BT *root,BT *next)
{
   char ch;
   cout<<"WHERE DO YO WANT TO INSERT NEWNODE INFO "<<root->data<<endl;
   cin>>ch;
   if(ch=='L'|| ch=='l')
   {
    if(root->LC==NULL)
    {
      root->LC=next;
    }
    else{
        insert(root->LC,next);
    }
   }else if(ch=='R' ||ch=='r')
   {
    if(root->RC==NULL)
    {
        root->RC=next;

    }
    else{
        insert(root->RC,next);
    }
   }

}

void BT::display(BT *root)
{
if(root==NULL)
{
    return;
}
else{
    display(root->LC);
    cout<<root->data<<endl;
    display(root->RC);
}
}


int main()
{
    BT b;
    b.Create();
   
    b.display(root);
    return 0;
}