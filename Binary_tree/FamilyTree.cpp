#include<iostream>
using namespace std;
class FT
{
int age ,adhar,Mob_no;
string Name,Address,Education;
FT *LC,*RC;

public:
  void create();
  void AddNew();
  void insert(FT *root,FT *next);
  void display(FT *root);
  void search(FT *root, int);

}*root;

void FT::create()
{
    root=new FT;
    cout<<"ENTER THE INFO OF HEAD OF FAMILY MEMBER: "<<endl;
    cout<<"ENTER NAME:"<<endl;
    cin>>root->Name;
    cout<<"ENTER AGE :"<<endl;
    cin>>root->age;
    cout<<"ENTER AADHAR NUMBER:"<<endl;
    cin>>root->adhar;
    cout<<"ENTER MOBILE "
}