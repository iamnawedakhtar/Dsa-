#include<iostream>
using namespace std;
struct node
{
    int data ;
     node * next; 
     node* pre;

    node (int d)
    {
        this->data=d;
        this->next=NULL;
        this->pre=NULL;
    }
};

void IsertAtHead(node * &head, int d)
{  
    if(head==NULL)
    {
        node* temp=new node(d);
        head =temp;
    }
    else
    {
    node * temp=new node(d);
    temp->next=head;
    head->pre=temp;
    head=temp;
    }
}
void deleteAtPos(node* head, node * tail, int pos)
{
    if (pos==1)
    {
        node* temp=head;
        head=head->next;
        delete temp;
        return ;
    }
    node * temp=head;
    int cnt=1;
    while(cnt<pos-1)
    {
        temp=temp->next;
        cnt++;
    }
    if(temp->next->next==NULL)   // DELETE AT TAIL
    {
         node * todelete=temp->next;
         todelete->pre=NULL;
         temp->next=temp->next->next;
         delete todelete;
         return ;
    }
    node * todelete=temp->next;
    temp->next=temp->next->next;
    temp->next->pre=temp;
    delete todelete;

}
void InsertAtBack(node * &tail,int d ,node* &head)
{   
    if(head==NULL)  // EMPTY LIST
    {
        node * temp=new node (d);
        head=temp;
        tail=temp;
    }
    else
    {
    node * temp=new node(d);
    tail->next=temp;
    temp->pre=tail;
    tail=temp;
    }
    

}

void InsertATPos(node * & head ,node* & tail ,int pos, int d)
{
    if(pos==1)
    {
        IsertAtHead(head ,d);
        return ;
    }
    node * temp=head;
    int cnt=1;
    while(cnt<pos-1)
    {
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL)
    {
        InsertAtBack(tail, d,head);
        return;
    }

    node * toinsert=new node(d);
    toinsert->next=temp->next;
    temp->next=toinsert;
    toinsert->pre=temp;
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
    node * node1=NULL;
    node * head=node1;
    node * tail=NULL;
    


int n;
cout<<" enters no"<<endl;

for(int i=0;i<5;i++)
{   
    cin>>n;
    InsertAtBack(tail,n,head);
}

print(head); cout<<endl;

deleteAtPos(head,tail,5);;
print(head); cout<<endl;

cout<<endl;
return 0;
}