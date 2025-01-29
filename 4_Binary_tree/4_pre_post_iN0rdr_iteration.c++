#include<iostream>
#include<stack>
using namespace std;
class node
{   
    public: 
    int data ;
    node* left;
    node* right;

    node(int d)
    {
        this->data=d;
        this->left= NULL;
        this->right-NULL;
    }


};
node* buildtree(node * root)
{  
    int data;
    cout<<"enterr data \n";
    cin>>data;
    root=new node(data);

    if(data==-1)    
    return NULL;

    cout<<"eneter data to put in left of "<< data<<endl;
    root->left=buildtree(root->left);

    cout<<"eneter data to put in right of "<< data<<endl;
    root->right=buildtree(root->right);
    return root ;

}
void in0rder(node *root )
{
   node * curr=root;
   stack<node *> s;
   
while(!s.empty() || curr !=NULL)
{
   while(curr)

   {
        s.push(curr);
        curr=curr->left;

   }

   if(curr==NULL && !s.empty())
   {
    node* temp=s.top();
    cout<<temp->data<<" ";
    s.pop();
    curr=temp->right;

   }   
     
}

}

void pre0rder(node *root )
{
   node * curr=root;

   stack<node *> s;
   
while(!s.empty() || curr !=NULL)
{
   while(curr)

   {    
        cout<<curr->data<<" ";
        s.push(curr);
        curr=curr->left;

   }

   if(curr==NULL && !s.empty())
   {
    node* temp=s.top();
 
    s.pop();
    curr=temp->right;

   }   
     
}

}

void post0rder(node *root )
{
   node * curr=root;
   stack<node *> s;
   
while(!s.empty() || curr !=NULL)
{  
    node* temp;
   while(curr)

   {         
        s.push(curr);
        curr=curr->left;
   }

    if(curr==NULL && !s.empty())
   { 
     temp=s.top();
     curr=temp->right;
     cout<<temp->data<<" ";
     s.pop();
   }   

}
}
int main()

{ 

node* root=NULL;
root=buildtree(root);
in0rder(root);
cout<<endl;

pre0rder(root);
cout<<endl;

post0rder(root);
cout<<endl;

//1 2 4 -1 -1 5 -1 -1 3 -1 -1




return 0;
}