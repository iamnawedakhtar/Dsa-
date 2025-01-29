#include<iostream>
using namespace std;
class queue {
    public:

    int *arr;
    int front;
    int rear;
    int size;

    queue(int size)  // constructor
    {
        this->size=size;
        arr=new int [size];
        front=0;
        rear=0;
    }

    void push(int element)
    {
       if(rear>size-1)
         cout<<" queue overflow ";
       else
       {
          arr[rear]=element;
          rear++;
       }
    }
     void pop()
    {
       if(rear==front)
         cout<<" queue is empty ";
       else
       {
          arr[front]=-1;
          front++;
       }
    }

    bool isEmpty()
    {
        if(rear==front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void elementAtfront()
    {
        if(rear==front)
        cout<<" queue is empty";
        else
          cout<<arr[front]<<endl;
    }
    

};
int main()
{ 
queue q(5);
q.push(1);
q.push(2);
q.push(3);
q.push(4);
q.push(5);

q.elementAtfront();
q.pop();
q.pop();
q.pop();
q.pop();
q.pop();

if(q.isEmpty())
cout<<" q is empty "<<endl;
else
cout<<" q is not empty \n";


return 0;
}