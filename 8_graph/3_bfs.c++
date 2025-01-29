
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
   
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int> ans;
        vector<bool> vis(V,false);
        
        queue<int>q;
        q.push(0);
        vis[0]=true;
        while(!q.empty())
        {   
            int top=q.front();
            ans.push_back(top);
            q.pop();
            for(auto it : adj[top])
            {
                if(!vis[it]) 
                {
                   q.push(it);
                   vis[it]=true;
                }

            }
        }
        return ans;
    }
};



