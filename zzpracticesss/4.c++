// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to n-1

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
 
    return true;
}

int count(int x)
{   
    int sum=0;
    for(int i=1;i<=x;i++)
    {
        if(isPrime(i))
        sum+=1;
    }
      
    return sum;
  
}

int main() {
int ans=0;

int l=1;
int r=2;
for(l;l<=r;l++)
{   
    int x=count(l);
    if((x%2)==0  && x!=0)
    ans+=1;
    
}
cout<<ans;
    return 0;
}