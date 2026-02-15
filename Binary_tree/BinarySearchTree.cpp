#include<iostream>
#include<string>
using namespace std;

class Student{
    int  id, seatNo,CETScore;
    string name,AddStatus;

    Student *LC ,*RC;

    public:
    void create();
    void addNew();
    void insert(Student *root,Student *next);
    void display(Student *root);
	void search(Student *root , int id); 
	void CountTotalStudent(Student *root);
	int HT(Student *root);
	void displayIITStudents(Student *root);
	void displayLowestCETScore(Student *root);
	void displayHighestCETScore(Student *root);
	void displayTopThree(Student *root);
}*root,*st[100];

void Student :: create()
{
    root=new Student;
	root->id=01;
    root->seatNo=101;
    root->name="Arti";
    root->CETScore=90;
	root->AddStatus="IIT";
	root->LC = NULL;
    root->RC = NULL;
}

void Student::addNew()
{
    
    int ch;
	do{  
    Student *next;
    next=new Student;                                            //NEW MEMBER PONTER                                         // MEMORY ALLOCATE
	cout<<"Enter the data of Student :-"<<endl;
	cout<<"Enter the id, seat number,CET score , name , add status of New student :-" <<endl;
 	cin>>next->id>>next->seatNo>>next->CETScore>>next->name>>next->AddStatus;
	next->LC=NULL;
	next->RC=NULL;
	insert(root,next);                                    //CALL INSERT FUNCTION
	cout<<"Do u want to add one more new family member (1/0) :-";
	cin>>ch;
	}while(ch==1);
}

void Student::insert(Student *root, Student *next)
{
    if (next->CETScore < root->CETScore) 
    {
        if (root->LC == NULL)
            root->LC = next;
        else
            insert(root->LC, next);
    }
    else 
    {
        if (root->RC == NULL)
            root->RC = next;
        else
            insert(root->RC, next);
    }
}


void Student:: display( Student *root)
{
Student *temp;
int top=-1;
temp=root;

if(root!=NULL)
{
	do{
		while(temp!=NULL)
		{
			top++;
			st[top]=temp;
			temp=temp->LC;
		}
		if(top!=-1)
		{
			temp=st[top];
			top--;
			cout<<"\n"<<temp->name<<"\t"<<temp->seatNo<<"\t"<<temp->AddStatus<<"\t"<<temp->id<<"\t"<<temp->CETScore<<endl;
			temp=temp->RC;

		}

	}while(temp!=NULL || top!=-1);
}
}


int f=0;
void Student::search(Student *root, int sid)
{
	if(root == NULL)
        return;
	
	if(root->id==sid){
			cout<<"\n"<<root->name<<"\n"<<root->AddStatus<<"\n"<<root->id<<"\n"<<root->seatNo<<"\n"<<root->CETScore<<"\n";

			f=1;
			return;
	}
		else{
        search(root->LC, sid);
        search(root->RC, sid);
}
	}

int count=0;
void Student::CountTotalStudent(Student *root)
{
	if(root == NULL)
	{
        return;
	}
	else{

    count++;
    CountTotalStudent(root->LC);
    CountTotalStudent(root->RC);
}
}

int Lht,Rht;
int Student::HT(Student *root)
{
  if(root==NULL)
  {
      return -1;
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

void Student::displayIITStudents(Student *root)
{
  if (root == NULL) 
  {
  return;
  }
  
      displayIITStudents(root->LC);
  
    if (root->AddStatus == "IIT") {
        cout<<"Name: "<<root->name<<"\n"<<"Status: "<<root->AddStatus<<"\n"<<"Student id: "<<root->id<<"\n"<<"Seat no: "<<root->seatNo<<"\n"<<"CET Score: "<<root->CETScore<<"\n";
    }
    

    
    displayIITStudents(root->RC);

}

void Student:: displayLowestCETScore(Student *root)
{
 if (root == NULL)
        return;

    while (root->LC != NULL)
        root = root->LC;

    cout << "\nLowest CET Score Student:\n";
    cout << root->name << "  " << root->CETScore << endl;

}

void Student::displayHighestCETScore(Student *root)
{
if (root == NULL)
        return;

    while (root->RC != NULL)
        root = root->RC;

    cout << "\nHighest CET Score Student:\n";
    cout << root->name << "  " << root->CETScore << endl;
}

int cnt = 0;
void Student::displayTopThree(Student *root)
{

    if(root==NULL || cnt>=3)
    {
        return;
    }

   
       displayTopThree(root->RC);
   

    if(cnt<3)
    {
        cout<<"\n"<<root->name
            <<"\n"<<root->AddStatus
            <<"\n"<<root->id
            <<"\n"<<root->seatNo
            <<"\n"<<root->CETScore<<"\n";
        cnt++;
    }
    
    displayTopThree(root->LC);

}

int main()
{
    Student s;
    int choice=0;
	

    s.create();

    do {
        cout << "\n MENU \n1. Add Student\n2. Display All\n3. Search Student\n4. Count Students\n5. Height of Tree\n6. Display IIT Students\n7. Lowest CET Score\n8. Highest CET Score\n9.Display top 3 students \n 10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            s.addNew();
            break;
        case 2:
            s.display(root);
            break;
        case 3:{
		int sid;
            cout << "Enter student id: ";
            cin >> sid;
           f=0;
            s.search(root, sid);
            if (f == 0)
                cout << "Student not found\n";
            break;
		}
		
        case 4:
            count=0;
            s.CountTotalStudent(root);
            cout<<"total students :\n"<<count;
            break;
        case 5:
            cout << "Height: " << s.HT(root) << endl;
            break;
        case 6:
            s.displayIITStudents(root);
            break;
        case 7:
            s.displayLowestCETScore(root);
            break;
        case 8:
            s.displayHighestCETScore(root);
            break;
            
        case 9:
            cnt=0;
             s.displayTopThree(root);
             break;
        case 10:
             exit(0);
             break;
        default:cout<<"wrong choice";
        }cout<<"\n want to go in menu again(1/0)\n"<<endl;
        cin>>choice;
    } while (choice==1);

    return 0;
}
