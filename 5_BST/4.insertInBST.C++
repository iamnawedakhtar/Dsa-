#include<iostream>
using namespace std;
class node {
    public:

    int data;
    node* left;
    node* right;
    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

void insert(node * &root, int element)   // doubt hai 
{   
    node* ROOT=root;
    node * prev=NULL;
    while(root!=NULL)
    {
        prev=root;
        if(element==root->data)
        {
          cout<<" element already exist \n";
          return;
        }

        if(element<root->data)
           root=root->left;
        else
           root=root->right;
        
    }
    node * newnode=new node(element);  // creating a new node to insert

    if(element<prev->data)
       prev->left=newnode;
    else
       prev->right=newnode;
    
    root=ROOT;
}

void pre0rder(node * root) // preorder traversal
{
   if(root!=NULL)
   {
    cout<<root->data<<" ";
    pre0rder(root->left);
    pre0rder(root->right);
    
   }
}

int main()
{ 
    
    node * p=new node(4);
    node *p1=new node(2);
    node *p2=new node(6);
    node *p3=new node(1);
    node *p4=new node(3);
    node *p5=new node(5);
    node *p6=new node(9);

    // linking nodes 
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->left=p5;
    p2->right=p6;

    node * root=p;
    
    insert(p,11);
     pre0rder(p);
    cout<<endl;
     insert(p,0);
     pre0rder(p);

return 0;
}