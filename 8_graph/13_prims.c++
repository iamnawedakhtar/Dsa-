#include <bits/stdc++.h>
using namespace std;
class Solution


{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {   
     
     priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
     
     vector<int>vis(V,0);
     
     pq.push({0,0}); //{dist,node}
     int sum=0;
     while(!pq.empty())
     {
         int node=pq.top().second;
         int wt=pq.top().first;
         
         pq.pop();
         
         if(vis[node]) continue; // mean i have already considered that node wiht min edge weight (priority q) also make sure karega to not go into cycle
         
         vis[node]=1;
         sum+=wt;
         
         for(auto it: adj[node])
         {
             int adjnode=it[0];
             int edw=it[1];
             if(!vis[adjnode])
             pq.push({edw,adjnode});
         }
         
      }
      return sum;
          
    }
};