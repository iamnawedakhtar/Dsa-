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
void insert(node * &tail,int data,int key)
{
   if(tail==NULL)   // list is empty
   {
    node * newnode=new node(data);
    tail=newnode;
    newnode->next=tail;
    return;
   }
  // list is not empty

  node *temp=tail;
  while(temp->data!=key)
  {
    temp=temp->next;
  }
  node * newnode=new node (data);
  newnode->next=temp->next;
  temp->next=newnode;

}
void print(node * tail)
{
    node * temp=tail;
    do
    {
          cout<<tail->data<<" ";
          tail=tail->next;

    }while(tail!=temp);
     cout<<endl;

}
int main()
{
    
    node *tail=NULL;
    insert(tail,10,10);

    insert(tail,20,10);
    insert(tail,30,20);
    insert(tail,40,10);
    insert(tail,50,30);

    cout<<tail->data<<endl;
    
    print(tail);
    return 0;


}