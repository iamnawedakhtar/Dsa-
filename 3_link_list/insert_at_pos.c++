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
void insertAtHead(node* &head,int d)
{
  node* temp=new node(d);
  temp->next=head;
  head=temp;
}
void insertAtback(node* &tail,int d) // inserting at back
{
    node* temp=new node(d);
    tail->next=temp;
    tail=temp;
}
void insertAtMiddle(node* tail,node* &head,int pos,int d) // inserting at middle
{   
    if(pos==1) // if we have to insert at head
    {
       insertAtHead(head,d);
       return;
    }
    node* temp=head;
    int cnt=1;
    while(cnt<pos-1)
    {   
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL)  // if we have to insert at tail
    {
        insertAtback(tail,d);
        return;
    }
   node *toInsert=new node(d);
   toInsert->next=temp->next;
   temp->next=toInsert; 
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
   node* node1=new node(10); // creating a node
   node* head=node1;
   node * tail=node1;
   insertAtback(tail,20); 
   insertAtback(tail,30);  
   insertAtback(tail,50);   
   print_list(head);
   insertAtMiddle(tail,head,5,60);
   print_list(head);
   cout<<" head -> "<<head->data<<endl;
   cout<<" tail -> "<<tail->data<<endl;
}