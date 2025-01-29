
#include <bits/stdc++.h>
using namespace std;
class Solution {
private: 
    int timer=0;

    private: 
    void dfs(int src, int parent, vector<int> &vis, vector<int> adj[],set<int> &ans,vector<int> &low, vector<int> &tin)
    {
        vis[src]=1;
        low[src]=tin[src]=timer;
        timer++;
        
        int child=0;
        for(auto it : adj[src])
        {   
            
            if(it==parent) continue;
            if(!vis[it])
            {
                dfs(it,src,vis,adj,ans,low,tin);
                low[src]=min(low[src],low[it]);

                if(low[it]>=tin[src] && parent!=-1) //changes from bridges
                {
                    ans.insert(src);
                }
                child++;
            }
            else
            {
                low[src]=min(low[src],tin[it]);   //changes from bridges
            }
        }
        if(child>1 && parent==-1) ans.insert(src);
    }    
  public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
               
        vector<int> low(n); //min of all adjacent nodes apart from partent and visited
        vector<int> tin(n);

        vector<int>vis(n,0);
        set<int>ans;  // ans sorted order me cahiye tha that is why it set it used and also one veritce may come multiple times so keep it unique

        dfs(0,-1,vis,adj,ans,low,tin);
        
        vector<int>temp;
        for(auto it :ans)
        {
            temp.push_back(it);
        }
        if(temp.size()==0) return {-1};
        return temp;
    }
};