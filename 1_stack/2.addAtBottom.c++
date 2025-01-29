// Online C++ compiler to run C++ program online
#include <iostream>
#include<stack>
using namespace std;
void addAtbottom(stack <int> &st,int n,int count)
{
// base case
if(count==0)
{
    st.push(n);
    return;
}
int num=st.top();
st.pop();

addAtbottom(st,n,count-1);

st.push(num);

}
void printStack(stack<int>st)
{   
  while(!st.empty())
  {
      int ans=st.top();
      cout<<ans<<" ";
      st.pop();
  }
    cout<<endl;
    
}

int main() {
   stack <int>st;
   st.push(4);
   st.push(3);
   st.push(2);
   st.push(1); 
   int count=st.size();
   int number;
   cout<<"enter no \n";
   cin>>number;
   printStack(st);
   addAtbottom(st,number,count);
   printStack(st);
   
    return 0;
}