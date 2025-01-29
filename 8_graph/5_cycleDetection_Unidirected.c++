
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to detect cycle in an undirected graph.

    //using dfs
    bool detect(int node ,int parent,int vis[],vector<int> adj[])
    {   
         vis[node]=1;
         for(auto adjacentnode: adj[node])
         {
             if(!vis[adjacentnode])
             {
                 if(detect(adjacentnode,node,vis,adj))
                 return true;
             }
             else if(adjacentnode!=parent) return true;
         }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        
        int vis[V]={0};
        for(int i=0;i<V;i++)
        {
            if(!vis[i] && detect(i,-1,vis,adj)) return true;
        }
        return false;
    }
};

//usign bfs

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool detect(int src ,int vis[],vector<int> adj[])
    {

        queue<pair<int,int> > q;  //{node,parent}
        vis[src]=1;
        q.push({src,-1});
        
        while(!q.empty())
        {    
             int node=q.front().first;
             int parent=q.front().second;
             q.pop();
             
             for(auto adjacentnode: adj[node])
             {
                 if(!vis[adjacentnode])
                 {
                     q.push({adjacentnode,node});
                     vis[adjacentnode]=1;
                 }
                 else if(adjacentnode!=parent) return true;
             }
             
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        
        int vis[V]={0};
        for(int i=0;i<V;i++)
        {
            if(!vis[i] && detect(i,vis,adj)) return true;
        }
        return false;
    }
};