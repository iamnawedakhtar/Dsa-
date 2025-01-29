#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
int main()
{ 
  struct node * head=NULL;
  struct node * second=NULL;
  struct node * thrd=NULL;

  head =new node();
  second =new node();
  thrd =new node();
  head->data=1;
  head->next=second;
  second->data=2;
  second->next=thrd;
  thrd->data=4;
  cout<<head->data<<endl;
  cout<<second->data<<endl;
  cout<<thrd->data<<endl;
  
  
return 0;
}