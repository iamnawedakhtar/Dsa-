
#include <bits/stdc++.h>
using namespace std;
class Solution {
    private: 
    int timer=1;

    private: 
    void dfs(int src, int parent, vector<int> &vis, vector<int> adj[],vector<vector<int>> &ans,vector<int> &low, vector<int> &tin)
    {
        vis[src]=1;

        low[src]=tin[src]=timer;
        timer++;

        for(auto it : adj[src])
        {
            if(it==parent) continue;
            if(!vis[it])
            {
                dfs(it,src,vis,adj,ans,low,tin);
                low[src]=min(low[src],low[it]);

                if(low[it]>tin[src])
                {
                    ans.push_back({it,src});
                }
            }
            else
            {
                low[src]=min(low[src],low[it]);
            }
        }
    }
public:

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int> adj[n];
        vector<int> low(n); //min lowest time insertion of all the adjacent nodes apart from parent
        vector<int> tin(n);
        for(auto it : connections)
        {
              adj[it[0]].push_back(it[1]);
              adj[it[1]].push_back(it[0]);
        }

        vector<int>vis(n,0);
        vector<vector<int>>ans;
        dfs(0,-1,vis,adj,ans,low,tin);
        return ans;
    }
};