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
void insertATtail(node* &tail, int d)
{   
    
    node* temp=new node(d);
    temp->pre=tail;
    tail->next=temp;
    tail=temp;
}
void insertATpos(node * &tail,node* & head,int d,int pos)
{   
    if(pos==1)    // if we have to insert at head position
{
    insertAThead(head,d);
    return;
}
    int cnt=1;
    node* toInsert=new node(d);
    node* temp=head;
    while(cnt<pos-1)
    {
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL)
    {
       insertATtail(tail,d);
       return;
    }
    toInsert->next=temp->next;
    temp->next->pre=toInsert;
    temp->next=toInsert;
    toInsert->pre=temp;
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
    // node* node1=new node(5);
    // node* head=node1;
    // node* tail=node1;
    node* head=NULL;
    node* tail=NULL;
    print(head);
    insertAThead(head,4);
    insertAThead(head,3);
    print(head);
    insertATpos(tail,head,50,1);
    print(head);
    return 0;
}