#include<iostream>
using namespace std;
class stack 
{
    public:
    int *arr;
    int top;
    int size;
    stack (int size)        // constructor
    {
        this->size=size;
        arr=new int[size];
        top=-1;
    }

void push(int element)
{
    if((size-top)>1)
    {
        top++;
        arr[top]=element;
    }
}
void pop()
{
    if(top>=0)
    top--;
}
void peek()
{  
    cout<< arr[top];
    
}
bool isempty()
{
    if(top==-1)
    return true;
    else 
    return false;
}
};
int main()
{ 
stack st(5);
st.push(2);
st.push(3);
st.push(4);  
st.peek();
st.pop();
st.peek();

// st.peek();

return 0;
}




