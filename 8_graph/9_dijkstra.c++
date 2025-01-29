
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
         vector<int>dis(V,1e9);
         
         priority_queue < pair<int,int>, vector<pair<int,int> >, greater<pair<int,int>>> pq;
         
         dis[S]=0;
         pq.push({0,S});
         
         while(!pq.empty())
         {
             int dist=pq.top().first;
             int node=pq.top().second;
             
             pq.pop();
             
             for(auto it: adj[node])
             {
                 int wt= it[1];
                 int adjacentnode=it[0];
                 
                 if(dist+wt< dis[adjacentnode])
                 {
                     dis[adjacentnode]=dist+wt;
                     pq.push({dis[adjacentnode],adjacentnode});
                 }
             }
         }
         return dis;
         
    }
};


//dijsktra using set (can reduce computation very less as compared to pq)