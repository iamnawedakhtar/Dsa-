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
int main()
{ 

node* root=NULL;
root=buildtree(root);

return 0;
}