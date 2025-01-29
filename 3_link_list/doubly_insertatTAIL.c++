#include<iostream>
using namespace std;
class node
{
   public:
    int data;
    node* pre;
    node* next;
    //constructor to create new node
    node(int d)
    {
        this->data=d;
        this->pre=NULL;
        this->next=NULL;
    }
};
void insertATtail(node* &tail, int d)
{
    node* temp=new node(d);
    temp->pre=tail;
    tail->next=temp;
    tail=temp;
}
int count(node* &head)
{ 
     node* temp=head;
     int count =0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
void print(node * head)
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
  node * node1=new node(4);
  node * head=node1;
  node* tail=node1;
  print(head);
  insertATtail(tail,5);
  insertATtail(tail,6);
  insertATtail(tail,7);
  print(head);
  cout<<" no of elemnts in the link list is :" << count(head);
  return 0;
}