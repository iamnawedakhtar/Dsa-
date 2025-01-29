#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
    node(int d) //constructor
    {
       this->data=d;
       this->next=NULL;
    }
};
void insertAtback(node* &tail,int d) // inserting at back
{
    node* temp=new node(d);
    tail->next=temp;
    // tail=tail->next;  // or tail=temp;
      tail=temp;
   
}
void print_list(node* &head)
{
    node* temp=NULL;
    temp=head;
    while(temp !=NULL)
    {
      cout<<temp->data<<" ";
      temp=temp->next;
    }   
    cout<<endl;
}
int main()
{ 
node* node1=new node(0); // creating a node
node* head=node1;
node * tail=node1;
// print_list(head); 
// insertAtback(tail,5);
// print_list(head);
// insertAtback(tail,6);
int i=0; int no;
cout<<"enter no t0 insert in list \n";
while(i<5)
{ 
  
  cin>>no;
  insertAtback(tail,no);
  i++;
}
print_list(head);
return 0;
}