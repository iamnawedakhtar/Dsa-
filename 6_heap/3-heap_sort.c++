#include<iostream>
#include<algorithm>
using namespace std;

void heapify(int arr[], int n , int i)
{
     int largest=i;
     int left=2*i;
     int right=2*i +1;

     if(left <=n && arr[largest]<arr[left])
     {
        largest=left;
     }
     if(right <=n && arr[largest]<arr[right])
     {
        largest=right;
     } 
     
     if(largest != i)
     {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
     }

}

void heapsort( int arr[], int size)
{     
      
      while(size>1)
      {
        swap(arr[1], arr[size]);
        size--;

        heapify(arr,size,1);
      }
}
int main()
{
    int arr[]={-1,70,60,55,45,50};
    int n=5;

    heapsort(arr,n);
    for (int i=1;i<=n;i++)
     {
        cout<<arr[i]<<" ";
     }
     cout<<endl;
     return 0;
    
}