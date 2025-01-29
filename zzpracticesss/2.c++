#include<iostream>
using namespace std;
struct node
{
    int data ;
    struct node * next; 
    node (int d)
    {
        this->data=d;
        this->next=NULL;
    }
};

void IsertAtHead(node * &head, int d)
{ 
   if(head==NULL)
   {
      node *temp=new node(d);
      head=temp;
   }
  else
  {
    node * temp=new node(d);
    temp->next=head;
    head=temp;
  }
}

void deleteAtpos(node * &head, int pos )
{
    if (pos==1)
    {
        node * temp=head;
        head=head->next;
        delete temp;
        return ;
    }
    int cnt =1;
    node* temp=head;
    while(cnt<pos-1)
    {
        temp=temp->next;
        cnt++;
    }
    node * todelt=temp->next;
    temp->next=temp->next->next;
    delete todelt;
}

void print(node * n)
{
   while(n!=NULL)
   {
    cout<<n->data<<" ";
    n=n->next;
   }
}
int main()
{ 
node *head=NULL;


int n;
for(int i=0;i<5;i++)
{   
    cin>>n;
    IsertAtHead(head,n);

}
// print(head); cout<<endl;

// deleteAtpos(head,5);
// print(head);

return 0;
}