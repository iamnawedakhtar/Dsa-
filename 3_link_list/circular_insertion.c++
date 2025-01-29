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
void insert(node* &tail,int elemnt,int d)
{
    // if list is empty
    if(tail==NULL)
    {
         node * temp=new node(d);
         tail=temp;
         temp->next=tail;
    }
    else    // when list is not empty ans assuming element is present 
{
          node * cur=tail;
          while(cur->data != elemnt)
          {
            cur=cur->next;
          }
          node * temp=new node(d);
          temp->next=cur->next;
          cur->next=temp;
}
}
void deletAtpos(node * &tail,int key)
{
   node* cur=tail;
   node * pre=NULL; 

   while(cur->data!=key)
   {   
       pre=cur;
       cur=cur->next;
   }
   node * todelete=cur;
   pre->next=cur->next;
   delete todelete;

}
void print(node* tail)
{
   node* temp=tail;
   do
   {
      cout<<tail->data<<" ";
      tail=tail->next;
   } while (tail!=temp);
   cout<<endl;
}
int main()
{   node* tail=NULL;
    insert(tail,5,9);
    print(tail);

    insert(tail,9,2);
    print(tail);

    insert(tail,2,3);
    print(tail);

    insert(tail,3,5);
    print(tail);

    insert(tail,2,1);
    print(tail);

   deletAtpos(tail,2);
   print(tail);
}