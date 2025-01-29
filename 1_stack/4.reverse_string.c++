#include<iostream>
#include<stack>

using namespace std;

int main()
{ 
string str="bhavya";
stack<char>st;
int i=0;
while(str[i]!='\0')
{
    st.push(str[i]);
    i++;

}
while(st.empty()!=1)
{
    char ans=st.top();
    cout<<ans<<" ";
    st.pop();
}
return 0;
}

