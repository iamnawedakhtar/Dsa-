#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
    node* pre;
    node(int data) //constructor
    {
       this->data=data;
       this->next=NULL;
       this->pre=NULL;

    }
};
void insertAthead(node * &head,int d)
{  
     if(head==NULL)  /// when list is empty
{
    node* temp=new node(d);
    head=temp;
}
else
{
    node* temp=new node(d);
    temp->next=head;
    head->pre=temp;
    head=temp;
}

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
    node* temp1=head;
    node* temp2=head;
    int cnt=1;
    int i=1;
    while (cnt<pos-1)
    {
       temp1=temp1->next;
       cnt++;
    }
    while (i<pos+1)
    {
       temp2=temp2->next;
       i++;
    }
    temp1->next=temp2;
    temp2->pre=temp1;
    // node* cur=head;
    // node * pre=NULL;
    // int cnt=1;
    // while(cnt<pos)
    // {
    //     pre=cur;
    //     cur=cur->next;
    //     cnt++;
    // }
    

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
   deleteATpos(head,4);
   print_list(head);
   
   return 0;
}