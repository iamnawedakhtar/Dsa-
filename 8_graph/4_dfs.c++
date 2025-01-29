#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // 1->  usign recursion
    
    void dfs(int el,vector<int> &ans,vector<bool>& vis,vector<int>adj[] )
    {       
            ans.push_back(el);
            vis[el]=true;
            for(auto it: adj[el])
            {
                if(!vis[it]) 
                {
                  dfs(it,ans,vis,adj);
                }
            }
    }

    // iterative way

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
         
         vector<int>ans;
         vector<bool>vis(V,false);
        //  dfs(0,ans,vis,adj);
         


         // iterative way
         stack<int>st;
         st.push(0);
         while(!st.empty())
        {
            int top_=st.top();
            st.pop();
            if(!vis[top_])
            {
                ans.push_back(top_);
                vis[top_]=true;
            }
            
            for(int i=0;i<adj[top_].size();i++)
            {
                if(!vis[adj[top_][i]]) st.push(adj[top_][i]);
            }
        }
         return ans;
    }
};
