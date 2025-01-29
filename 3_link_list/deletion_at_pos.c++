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
void deleteATpos(node* &head,int pos )
{   
    if(pos==1)  // delete first element
    { 
    node* temp=head;
      head=head->next;
      delete temp;
      return;
    }
    node* temp=head;
    node* temp1=head;
    int cnt=1;
    int i=1;
    while (cnt<pos-1)
    {
       temp=temp->next;
       cnt++;
    }
     node * todelete=temp->next;

    while (i<pos+1)
    {
       temp1=temp1->next;
       i++;
    }
    temp->next=temp1;
    
    delete todelete;
}
void print_list(node *head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{ 
   node* node1=new node(10); // creating a node
   node* head=node1;
   insertAthead(head,20);
   insertAthead(head,30);
   insertAthead(head,40);
   print_list(head);
   deleteATpos(head,1);
   print_list(head);
   
   return 0;
}