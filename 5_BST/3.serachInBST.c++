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

bool searchBST(node * root,int key)  // iterative way
{  
    while(root!=NULL)
    {
       
      if(root->data==key)
      return 1;

      if(key<root->data)
      root=root->left;
      else
      root=root->right;
    }

   return 0; 
}
bool searchBST2(node * root,int key)  // recusrsion way
{  
    if(root==NULL)
      return 0;

    if(root->data==key)
       return 1;
    
    if(key<root->data)
       return searchBST2(root->left,key);
    else
       return searchBST2(root->right,key);
     
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
    

    if(searchBST2(p,89))
       cout<<" found \n";

    else 
       cout<<"not found";
   

return 0;
}