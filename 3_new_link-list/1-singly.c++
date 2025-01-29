#include<iostream>
using namespace std;
class node{
    public:
    int data ;
    node *next; 
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void IsertAtHead(node* &head, int data)
{
    node *toInsert=new node(data);
    toInsert->next=head;
    head=toInsert;
}
void IsertAtTail(node* &tail,int data)
{
   node *toInsert=new node(data);
   tail->next=toInsert;
   tail=toInsert;
}
void insertAtPos(int key,int data,node* &head,node* &tail)
{
    if(head->data==key) // insert at head or head position
   { 
     IsertAtHead(head,data);
     return;
   }

    node * temp=head;
    while(temp->data!=key)
    {
        temp=temp->next;
    }
    
    node* toinsert=new node(data);
    toinsert->next=temp->next;
    temp->next=toinsert;

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
   delete Todelete;

}
int main()
{ 
node *newnode=new node(10);
node* head,*tail;

head=newnode;
tail=newnode;


IsertAtHead(head,20);
IsertAtTail(tail,30);

print(head);
insertAtPos(30,50,head,tail);

Todelete(50,head);
print(head);



return 0;
}