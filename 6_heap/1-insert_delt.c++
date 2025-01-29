#include<iostream>
#include<algorithm>
using namespace std;

class heap
{   
    public:
    int arr[100];
    int size;
    
    heap()
    {
        arr[0]=-1;
        size=0;
    }

    void insert(int val)
    {
        size=size+1;
        int index=size;
        arr[index]=val;

         while(index>1)
         {
            int parent=index/2;
            if(arr[parent] < arr[index])
            {
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else
            {
                return ;
            }
         }
    }
    
    void dlt()
    {
        arr[1]=arr[size];
        size=size-1;
        
        int i=1;
        while(i < size)
        {
              int leftchild=2*i;
              int rightIndex=(2*i)+1;
              
         if (leftchild <= size && arr[i] < arr[leftchild] && arr[leftchild] > arr[rightIndex])
            {
                swap(arr[i], arr[leftchild]);
                i = leftchild;
            }

            else if (rightIndex <= size && arr[i] < arr[rightIndex] && arr[leftchild] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }    
            else 
            {
                return;
            }
        }

    }
    void print()
    {
        for(int i=1;i<=size;i++)
        {
            cout<<arr[i]<<" ";
        }
         cout<<endl;
    }
};

int main()
{ 

heap h;
h.insert(50);
h.insert(55);
h.insert(53);
h.insert(52);
h.insert(54);


h.print();

h.dlt();
h.print();
h.dlt();
h.print();
return 0;
}