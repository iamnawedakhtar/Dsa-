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
void insertAThead(node * &head,int d)
{
    node* temp=new node(d);
    temp->next=head;
    head->pre=temp;
    head=temp;

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
  print(head);
  insertAThead(head,5);
  insertAThead(head,6);
  insertAThead(head,7);
  print(head);
  
  return 0;
}