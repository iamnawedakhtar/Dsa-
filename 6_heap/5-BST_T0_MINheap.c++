
#include<iostream>
#include<algorithm>
using namespace std;

void heapify(int arr[], int n , int i)
{
     int smallest=i;
     int left=2*i;
     int right=2*i +1;

     if(left <=n && arr[smallest]>arr[left])
     {
        smallest=left;
     }
     if(right <=n && arr[smallest]>arr[right])
     {
        smallest=right;
     } 
     
     if(smallest != i)
     {
        swap(arr[smallest],arr[i]);
        if(arr[left]>arr[right])
        {
            swap(arr[left],arr[right]);
        }
        heapify(arr,n,smallest);
     }

}
int main()
{
    int arr[]={-1,4 ,2 ,6, 1, 3, 5, 7};
    int n=7;
    for(int i=n/2; i>0;i--)
    {
        heapify(arr,n,i);
    }

    for (int i=1;i<=n;i++)
     {
        cout<<arr[i]<<" ";
     }
     cout<<endl;
     return 0;
    
}