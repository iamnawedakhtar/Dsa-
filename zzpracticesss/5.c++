// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

void multilpy(vector<int>arr, int x)
{
    int carry=0;
    int i;
    for( i=0;i<arr.size(); i++)
    {
        int prod=arr[i]*x +carry;
        
        arr.insert(arr.begin() + i, prod%10);
        
        carry=prod/10;
    }
    while(carry)
    {
        
        arr.insert((arr.begin() + arr.size()), carry);
        carry=carry/10;
    }
    
}
int main() {
    vector<int>arr;
    arr.push_back(1);
    cout<<"enter n \n";
    int n;
    cin>>n;
    
    for(int x=2;x<=n; x++)
    {
        multilpy(arr, x);
    }
    
    for(int i=arr.size()-1;i>=0; i--)
    {
        
       cout<<arr[i];
       
    }    

    return 0;
}