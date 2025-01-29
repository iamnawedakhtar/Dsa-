#include<iostream>
#include<queue>
using namespace std;
class node
{  
    public:

    int data;
    node* left ;
    node* right;

    node (int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;

    }
};

node*  buildtree( node * root, int n)
{   
      if(root==NULL)
      {
        root=new node(n);
        return root;
      }

      if(n>root->data)
      {
        root->right=buildtree(root->right,n);
      }
      else
      {
        root->left=buildtree(root->left,n);
      }
      return root;
}
void input (node* &root)
{   
    int d;
    cout<<"enter data\n";
    cin>>d; 
    while(d!=-1)
    {
        cout<<"enter data\n";  
        buildtree(root,d);
        cin>>d; 
    }
    
}
void level0rder(node * root)
{
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node *temp=q.front();
        q.pop();
        
        if(temp==NULL)
        {  
            cout<<endl;
           if(!q.empty())
           {
            q.push(NULL);
           }
           
        }
        else
        {   
            cout<<temp->data<<" ";
            if(temp->left)
            q.push(temp->left);

            if(temp->right)
            q.push(temp->right);
            
        }   
    }

}
int main()
{ 
node* root=NULL;

input(root);
level0rder(root);

return 0;
}