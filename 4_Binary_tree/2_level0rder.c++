#include<iostream>
#include<queue>
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

// void level0rder(node * root)
// {
//     queue<node*>q;
//     q.push(root);

//     while(!q.empty())
//     {
//         node *temp=q.front();
//         q.pop();
        
//         if(temp!=NULL)
//         {
//             q.push(temp->left);
//             q.push(temp->right);
//             cout<<temp->data<<" ";
           
//         }

        
//     }

// }
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
// 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1 

int main()
{ 

node* root=NULL;
root=buildtree(root);
cout<<" printing the data in level order "<<endl;
level0rder(root);


return 0;
}