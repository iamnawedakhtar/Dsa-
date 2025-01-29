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
void dlte(node * root,int key)
{  
    node * prev=NULL;

    while(root->left!=NULL && root->right!=NULL) // when deleteing node is leaf node
    {
        prev=root;
        if(root->data==key)
           break;
        if(key<root->data)
           root=root->left;
        else
           root=root->right;
    }
    node * toDelete;
    if(prev->left->data==key){
        toDelete=prev->left;
        prev->left=NULL;
    }
    else {
        toDelete=prev->right;
        prev->right=NULL;
    }

    
    delete toDelete;
}

node* minval(node * root)
{
    
    while(root->left!=NULL)
    {
       root=root->left;
    }  
    return root;
}
node*  deleteNode (node* root, int x)
{
    if(root==NULL)
    {
        return root;
    }
    if( root->data==x)
    {
         // leaf node
         if(root->left==NULL && root->right==NULL)
         {
              delete root;
              return NULL;
         }
         // 1 node at left 
         if(root->left!=NULL && root->right==NULL)
         {    
              node* temp=root->left;
              delete root;
              return temp;
         }
         // 1 child at right
         if(root->left==NULL && root->right!=NULL)
         {
              node* temp=root->right;
              delete root;
              return temp;
         }
         // 2 child
         if(root->left==NULL && root->right==NULL)
         {
              int min=minval(root->right)->data;
              root->data=min;
              root->right=deleteNode(root->right,min);
              return root;
         }                  
    }

    else if(x>root->data)
    {
        root->right=deleteNode(root->right,x);
        return root;
    }
    else{
        root->left=deleteNode(root->left,x);
        return root;
    }

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

    pre0rder(p);
    cout<<endl;
    deleteNode(p,5);
    pre0rder(p);

return 0;
}