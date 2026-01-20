#include<iostream>
using namespace std;

class FT{                 //FAMILY TREE
	string name,edu,add;  //FAMILY MEMBER INFO
	int AN,CN,age;
	FT *LC,*RC ;          //LEFT CHILD AND RIGHT CHILD OF FAMILY TREE I.E BINARY TREE
	
	public :
		void create();    //CREATE FUNCTION TO GET INFO OF HEAD OF FAMILY
		void addNewMem();   //FUNCTION TO ADD NEW FAMILY MEMBER IN FAMILY TREE
		void insertMem(FT *root,FT *next); //INSERT THE FAMILY MEMBER TO LEFT SIDE OR RIGHT SIDE
		void displayFamily(FT *root);      //DISPLAY 
		void searchMem(FT *root,int ADN);    //SEARCH PARTICULAR FAMILY MEMBER BY TAKING AADHAR NO. BEACUSE IT IS UNIQUE
	    int HT(FT *root);                   //HEIGHT
	    void displayLeaf(FT *root);         //DISPLAY LEAF NODES(ZERO CHILD NODES)
	    void displayCurrent(FT *root,int height,int level);  //DISPLAY CURRENT GENERATION
	    void displaySibling(FT *root , int ADN);             //DISPLAY SIBLINGS(CHILD OF SAME PARENT )
		int displayAncestors(FT *root,int ADN);              //DISPLAY ANCESTOR
	}*root=NULL;                                             //POINTER FOR ROOTNODE


void FT :: create(){
	root = new FT;                                           //MEMORY ALLOCATION
	cout<<"Enter the data of head of the Family :-"<<endl;
	cout<<"Enter the name , age , Education , Address , Aadhar No and Contact No of Head :- " <<endl;
 	cin>>root->name>>root->age>>root->edu>>root->add>>root->AN>>root->CN;
	root->LC=NULL;                                            //LC AND RC SET TO NULL
	root->RC=NULL;
}

void FT :: addNewMem(){
	int ch;
	do{
	FT *newMem;                                               //NEW MEMBER PONTER
	newMem = new FT ;                                         // MEMORY ALLOCATE
	cout<<"Enter the data of New Family Member :-"<<endl;
	cout<<"Enter the name , age , Education , Address , Aadhar No and Contact No of New family Member :-" <<endl;
 	cin>>newMem->name>>newMem->age>>newMem->edu>>newMem->add>>newMem->AN>>newMem->CN;
	newMem->LC=NULL;
	newMem->RC=NULL;
	insertMem(root,newMem);                                    //CALL INSERT FUNCTION
	cout<<"Do u want to add one more new family member (1/0) :-";
	cin>>ch;
	}while(ch==1);

}

void FT :: insertMem(FT *root,FT *newMem){
	char ch;
	cout<<"Where do u want to insert "<<newMem->name<<" to Elder or Younger child of "<<root->name<<"(E/Y)";
	cin>>ch;

	if(ch =='E' || ch=='e'){
		if(root->LC==NULL){
			root->LC=newMem;
		}
		else{
			insertMem(root->LC,newMem);               //RECURSIVELY CALL INSERT FUNCTION
		}
	}
	else if(ch=='Y' || ch=='y'){
		if(root->RC==NULL){
			root->RC=newMem;
		}
		else{
			insertMem(root->RC,newMem);
		}
	}
}

void FT :: displayFamily(FT *root){
	if(root==NULL){
		return;
	}
	else{
		cout<<"Name :- "<<root->name<<"\n Age :- "<<root->age<<"\n Education :- "<<root->edu<<"\n Address :- "<<root->add<<"\n Aadhar No :- "<<root->AN<<"\n Contact No :- "<<root->CN;
		displayFamily(root->LC);
		displayFamily(root->RC);
		}
	}
int f=0;

void FT :: searchMem(FT *root,int ADN){
    if(root == NULL)
        return;
	
	else{	if(root->AN==ADN){
			cout<<"Name :- "<<root->name<<"\n Age :- "<<root->age<<"\n Education :-" <<root->edu<<"\n Address :- "<<root->add<<"\n Aadhar No :- "<<root->AN<<"\n Contact No :- "<<root->CN;
			f=1;
			return;
		}
		else{
			searchMem(root->LC,ADN);
			searchMem(root->RC,ADN);
	}
	}
}



void FT :: displaySibling(FT *root ,int ADN){
    if(root==NULL)
    {
        return;
    }else if(root->LC!=NULL && root->LC->AN==ADN)
    {
        if(root->RC!=NULL)
        {
            cout<<"Name :- "<<root->RC->name<<"\n Age :- "<<root->RC->age<<"\n Education :-" <<root->RC->edu<<"\n Address :- "<<root->RC->add<<"\n Aadhar No :- "<<root->RC->AN<<"\n Contact No :- "<<root->RC->CN;
        }else
        {
            cout<<"NO slibling found\n"<<endl;
        }
    }else if(root->RC!=NULL && root->RC->AN==ADN)
    {
        if(root->LC!=NULL)
        {
        cout<<"Name :- "<<root->LC->name<<"\n Age :- "<<root->LC->age<<"\n Education :-" <<root->LC->edu<<"\n Address :- "<<root->LC->add<<"\n Aadhar No :- "<<root->LC->AN<<"\n Contact No :- "<<root->LC->CN;
    }
    else{
        cout<<"no sibling found\n"<<endl;
        
    }
}
else{
	cout<<"Sibling not found\n";
}
}

int FT :: displayAncestors(FT *root,int ADN)
{
	if(root==NULL)
	{
		return 0;
	}
	if(root->AN==ADN)
	{
		return 1;
	}
	cout<<"Ancestor:\n";
	if(displayAncestors(root->LC,ADN) || displayAncestors(root->RC,ADN))
	{   
		
		cout<<"Name :- "<<root->name<<"\n Age :- "<<root->age<<"\n Education :-" <<root->edu<<"\n Address :- "<<root->add<<"\n Aadhar No :- "<<root->AN<<"\n Contact No :- "<<root->CN;
	     return 1;
	}
	return 0;
	
}

	
	
int Lht,Rht;
int FT :: HT(FT *root)
{
  if(root==NULL)
  {
      return 0;
  }
  Lht=HT(root->LC);
  Rht=HT(root->RC);
  if(Lht>=Rht)
  {
      return Lht+1;
      
  }
  else{
     return Rht+1; 
  }
  
}

 void FT :: displayLeaf(FT *root)
 {
     if(root==NULL)
     {
         return;
     }
     else if(root->LC==NULL&& root->RC==NULL)
     {
         	cout<<"Name :- "<<root->name<<"\n Age :- "<<root->age<<"\n Education :-" <<root->edu<<"\n Address :- "<<root->add<<"\n Aadhar No :- "<<root->AN<<"\n Contact No :- "<<root->CN;
         	
     }
     else
     {
         displayLeaf(root->LC);
         displayLeaf(root->RC);
     }
 }
int L;
void FT :: displayCurrent(FT *root ,int height,int level)
{
    if(root==NULL)
    {
        return;
    }else if(height==level)
    {
        cout<<"Name :- "<<root->name<<"\n Age :- "<<root->age<<"\n Education :-" <<root->edu<<"\n Address :- "<<root->add<<"\n Aadhar No :- "<<root->AN<<"\n Contact No :- "<<root->CN;
         	
    }else
    {
        displayCurrent(root->LC,height,level+1);
        displayCurrent(root->RC,height,level+1);
    }
}
	




int main(){
	FT m;
	int ADN;
	int ch,c=0;
	do{
		cout<<"Enter Your Choice :-\n 1.Create head of the family\n 2.Add family Member\n 3.Serach for Family Member\n 4.Display\n 5.Height of Family Tree\n 6.Display leaf node info\n7.Display current generation\n 8.display Siblings\n9.Display Ancestor\n 10.Exit\n";
		cin>>ch;
		cout<<"***********************************\n";

		switch (ch)
		{
		case 1:
		
			m.create();
			break;
		
		case 2 :
		
			if(root==NULL){
				cout<<"Root Node not created first u need to create root node :-\n";
				m.create();
			}
			else{
				m.addNewMem();
			}
			break;
		
			case 3 :
			
			if(root==NULL){
			cout<<"Family Tree doesn't exist first create a tree"<<endl;
		    return 0;
	        }
			else{
			int ADN;
			f=0;
	        cout<<"Enter the Aadhar Number of Family Memeber u want to search :-"<<endl;
	        cin>>ADN;
				m.searchMem(root,ADN);
				if(f==0){
				cout<<"Family Member not Found"<<endl;
				}
			}
				break;
			
			case 4 :
			
				m.displayFamily(root);
				break;
				
			case 5:
			
			int height;
			      height=m.HT(root);
			       cout<<"height of tree: \n"<<height;
			       break;
			
			case 6: 
			m.displayLeaf(root);
			break;
			
			case 7:
			       height=m.HT(root);
			       m.displayCurrent(root,height,0);
			       break;
			       
			case 8: 
			      cout<<"ENTER adhar number of member to find sibling\n  "<<endl;
			      cin>>ADN;
			      m.displaySibling(root , ADN);
			      break;

			case 9:
			       int ADN;
			      cout<<"ENTER adhar number of member to find Ancestor\n  "<<endl;
			      cin>>ADN;
			      m.displayAncestors(root,ADN);
			      break;
			case 10:
				exit(0);
				break;

		default: cout<<"invalid choice";
			
		}
		cout<<"\nDO YOU WANT TO GO IN MENU AGAIN \n(1/0)"<<endl;
		cin>>c;

	}while(c==1);
	
	return 0;

	}