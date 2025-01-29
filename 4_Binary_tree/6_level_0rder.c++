#include<iostream>
#include<queue>
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

node * buildtree(node* root)
{   
    
    cout<<"enter data \n";
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1)
    {
        return NULL;  // to stop inerting after that node 
    }

    cout<<" enter data to put left of root: "<<data<<endl;
    root->left =buildtree(root->left);
    
    cout<<" enter data to put right of root: "<<data<<endl;
    root->right =buildtree(root->right);
    return root;
}

void level0rder(node * root)
{
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* temp=q.front();
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
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
        }

    }
}

int main()
{ 

node * firstRoot=NULL;

node * root=buildtree(firstRoot);
level0rder(root);

return 0;
}
// 3 5 7 -1 -1 8 -1 -1 6 -1 9 -1 -1