#include<iostream>
using namespace std;
class stack {
    public: int *arr ;
            int top1;
            int size;
            int top2;  // implementing 2 stacks using same array 
    
    stack (int length)  // constructor
    {
         this->size=length;
         arr=new int [length];
         top1=-1;
         top2=length;
    }
    void push1(int element)
    {
        if( (top2-top1>1))
        {
            top1++;
            arr[top1]=element;
        }
        else 
        {
            cout<<" stck1 overflow "<<endl;
        }
    }
     void push2(int element)
    {
        if((top2-top1>1))
        {
            top2--;
            arr[top2]=element;
        }
        else 
        {
            cout<<" stck2 overflow "<<endl;
        }
    }
    void pop1 ()
    {
        if(top1>=0)
        {
            top1--;
        }
        else 
        {
            cout<<" stack underflow";
        }
    }
     void pop2 ()
    {
        if(top2<size )
        {
            top2++;
        }
        else 
        {
            cout<<" stack underflow";
        }
    }
    void peek1()
{  
    cout<< arr[top1]<< " ";
}
    void peek2()
{  
    cout<<arr[top2]<< " ";   
}
bool isempty1()
{
    if(top1==-1)
    return true;
    else 
    return false;
}
bool isempty2()
{
    if(top2==size)
    return true;
    else 
    return false;
}

};

int  main()
{ 
    stack st(5);
    st.push1(3);
    st.push1(2);
    st.push1(1);
    st.push2(5);
    st.push2(4);
    
   cout<< st.isempty1()<<" ";

   cout<<st.isempty2()<<" ";
    st.peek1();
    st.peek2();

return 0;
}