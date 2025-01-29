#include<iostream>
#include<queue>
using namespace std;
int main()
{ 
  
//   priority_queue<int> pq;
//   pq.push(4);
//   pq.push(6);
//   pq.push(2);
//   pq.push(10);
//   pq.push(9);

//   cout<<"element at top "<<pq.top()<<endl;
//   pq.pop();
//   cout<<"element at top "<<pq.top()<<endl;
//   cout<<"size of the heap "<<pq.size()<<endl;

  priority_queue<int ,vector<int>,greater<int> >pq;
  pq.push(4);
  pq.push(6);
  pq.push(2);
  pq.push(10);
  pq.push(9);

  cout<<"element at top "<<pq.top()<<endl;
  pq.pop();
  cout<<"element at top "<<pq.top()<<endl;
  cout<<"size of the heap "<<pq.size()<<endl;

return 0;
}