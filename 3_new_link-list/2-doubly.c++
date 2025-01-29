#include<iostream>
using namespace std;
class node{
    public:
    int data ;
    node *next;
    node *pre;  
    node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->pre=NULL;
    }
};
void insert(node* &head,int data)
{
    if(head==NULL)   //list is empty
    {
      node *newNode=new node(data);
      head=newNode;
      return;
    }
    
    node *newNode=new node(data);
    head->pre=newNode;
    newNode->next=head;
    head=newNode;

}
void insertAtPos(node * &head,int data,int key)
{
    if(head->data==key)  // insert at head
    {
       node *newNode=new node(data);
       head->pre=newNode;
       newNode->next=head;
       head=newNode;
       return;

    }
    node * temp=head;
    while(temp->data!=key)
    {
        temp=temp->next;
    }
     
    node *newNode=new node(data);
    temp->next->pre==newNode;
    newNode->next=temp->next;
    temp->next=newNode;
}
void print(node * head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
void Todelete(int key, node* &head)
{
  if(head->data==key) // delete at head
  {
    node*Todelete=head;
    head=head->next;
    head->pre=NULL;
    delete Todelete;
    return;
  }

  node * temp=head;
  node * pre=NULL;
  while(temp->data!=key)
    {   
        pre=temp;
        temp=temp->next;
    }
   node * Todelete=temp;
   pre->next=temp->next;
   temp->next->pre=temp->pre;
   delete Todelete;

}
int main()
{   
    node *head=NULL;
    node *tail=NULL;
    insert(head,10);
    insert(head,20);
    insert(head,30);
    insert(head,40);
    insert(head,50);
    print(head);
    // insertAtPos(head,60,20);

    // Todelete(10,head);  there is some doubt 
    print(head);
    return 0;
}