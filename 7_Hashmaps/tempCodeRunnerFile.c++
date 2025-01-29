// #include<iostream>
// using namespace std;
// class node{
// 	public:
// 	node* left;
// 	node* right;
// 	int data;
// 	node(int d){
// 		data=d;
// 		left=NULL;
// 		right=NULL;
// 	}
// };

// node* createtreeusingpostorderandinorder(int* postorder,int* inorder,int s,int e,int &i){

// 	//base case
// 	if(s>e){
//     return NULL;
// 	}
//      //recursive case
// 	int d=postorder[i];
// 	int index=-1;
// 	i--;
// 	for(int k=s;k<=e;k++){
// 		if(d==inorder[k]){
// 			index=k;
// 			break;
// 		}
// 	}
// 	node *root=new node(d);

//    root->right=createtreeusingpostorderandinorder(postorder,inorder,index+1,e,i);
// 	root->left=createtreeusingpostorderandinorder(postorder,inorder,s,index-1,i);
   
	
// 	return root;

// }
// void inorderprint(node* root){
// 	//base case
// 	if(root==NULL){
// 		return;
// 	}
// 	if(root->left==NULL){
// 		cout<<"END";
// 	}
// 	else{
// 		cout<<root->left->data;
// 	}
// 	cout<<" "<<"=> "<<root->data<<" "<<"<= ";
// 	if(root->right==NULL){
// 		cout<<"END"<<endl;
// 	}
// 	else{
// 		cout<<root->right->data<<endl;
// 	}
//     inorderprint(root->left);
// 	inorderprint(root->right);

// }

// int main() {
	
// 	int n;
// 	cin>>n;
// 	int postorder[n];
// 	for(int i=0;i<=n-1;i++){
// 		cin>>postorder[i];
// 	}
	
// 	int m;
// 	cin>>m;
// 	int inorder[m];
// 	for(int i=0;i<=m-1;i++){
// 		cin>>inorder[i];
// 	}
//    int 
// 	node* root=createtreeusingpostorderandinorder(postorder,inorder,0,m-1, n-1);
// 	inorderprint(root);

//    return 0;
	
// }