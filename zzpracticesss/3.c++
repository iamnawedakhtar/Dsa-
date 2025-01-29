// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    int arr[]={1,2,3,3,5,5};
    int ans=0;
    for(int i=0;i<6;i++)
    {
        ans=ans^arr[i];
        cout<<ans<<" "; 
    }
    cout<<endl;
     for(int i=1;i<6;i++)
    {
        ans=ans^i;
         cout<<ans<<" ";
        
    }
    cout<<endl;
    cout<<ans;
    
    

    return 0;
}