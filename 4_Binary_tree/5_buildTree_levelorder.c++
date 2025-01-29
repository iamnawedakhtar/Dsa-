#include<iostream>  // doubt
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
void buildtree(node * &root)
{  
    int data;
    cout<<"enter data for root node ";
    cin>>data;
    root=new node(data);

    queue<node *>q;
    q.push(root);

    while(!q.empty())
    {
        node* temp= q.front();
        q.pop();

        cout<<"enter data to put left of "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata !=-1)
        {
            node* leftnode=new node(leftdata);
            temp->left=leftnode;
            q.push(leftnode);
        }
        
        cout<<"enter data to put right of "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata !=-1)
        {
            
            temp->right=new node(rightdata);
            q.push(temp->right);
        }            
    }

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
void searchBST2(node * root,int key, bool &present)  // recusrsion way
{  
    if(root==NULL)
      return ;

    if(root->data==key)
    {
       present=1;
       return;
    }
       
    
        searchBST2(root->left,key,present);

        searchBST2(root->right,key,present);
    
     
}
int main()
{ 

node* root=NULL;
buildtree(root);
bool ispresent=0;
searchBST2(root,5,ispresent);

if(ispresent)
{
    cout<<"element is present in the tree \n";

}
else{
     cout<<"element is not present in the tree \n";
}

// level0rder(root);
return 0;
}