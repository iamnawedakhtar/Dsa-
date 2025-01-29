
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0);   // 1 based indexing
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {   
     
     priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int> >> > pq;
     
    DisjointSet ds(V);
     
     for(int i=0;i<V;i++)
     {
         for(auto it: adj[i])
         {
             int adjnode=it[0];
             int edw=it[1];
             pq.push({edw,{i,adjnode}}); //{edge weight, { node i , node j}}
         }         
     }
     int sum=0;
     while(!pq.empty())
     {
         int wt=pq.top().first;
         int u=pq.top().second.first;
         int v=pq.top().second.second;
         
         pq.pop();
         
        if(ds.findUPar(u)!=ds.findUPar(v))
        {
            sum+=wt;
            ds.unionByRank(u,v);
        }
         
      }
      return sum;
          
    }
};