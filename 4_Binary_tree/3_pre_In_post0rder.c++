#include<iostream>
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
    if (root == NULL)
    return;
    
    in0rder(root->left);
    cout<<root->data<<" ";
    
    in0rder(root->right);
}

void Post0rder(node *root )
{
    if (root == NULL)
    return;

    Post0rder(root->left);
   

    Post0rder(root->right);
     cout<<root->data<<" ";
}

void Pre0rder(node *root )
{
    if (root == NULL)
    return;
    
    cout<<root->data<<" ";
    Pre0rder(root->left);
    

    Pre0rder(root->right);
}
int main()
{ 

node* root=NULL;
root=buildtree(root);
in0rder(root);
cout<<endl;

Pre0rder(root);
cout<<endl;

Post0rder(root);
cout<<endl;


return 0;
}
// 1 2 4 -1 -1 5 -1 -1 3 -1 -1