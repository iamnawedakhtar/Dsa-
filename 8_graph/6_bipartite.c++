#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<bool>vis(n,0);
        vector<int>color(n,0);

        queue<int>q;

        for(int i=0;i<graph.size();i++)
        {
            
            if(!vis[i])
            {
                q.push(i);
                vis[i]=true;
                color[i]=1;
                while(!q.empty())
                {
                   int top=q.front();
                   int col=color[top];

                   q.pop();
                   for(auto adjnode: graph[top])
                   {
                       if(!vis[adjnode])
                       {  
                          vis[adjnode]=1;
                          color[adjnode]=col*-1;
                          q.push(adjnode);
                       }  
                       else if(color[adjnode]==color[top])
                       {
                           return false;
                       }
                   }
                }
            }
        }
        return true;
    }
};