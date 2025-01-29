#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
    node(int data) //constructor
    {
       this->data=data;
       this->next=NULL;
    }
};
void insertAthead(node* &head,int d)
{
  node* temp=new node(d);
  temp->next=head;
  head=temp;  
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
node* node1=new node(3); // creating a node
node* head=node1;
print_list(head); 


return 0;
}