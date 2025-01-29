// ddirected graph me shortest path using topo for single src to all nodes
// should be directed acyclic graph ...can use dijsktra here but it will be computanionlay not effiecient


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
     void dfs(int src, stack<int>& st, vector<vector<pair<int,int> >> &adj,vector<int> &vis)
     {
         vis[src]=1;
          for(auto node: adj[src])
          {
              if(!vis[node.first]) dfs(node.first,st,adj,vis);
              
          }
           st.push(src);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
       
        // adjacency list
        vector<vector<pair<int,int>>>adj(N);
        vector<int> ans(N, 1e9); // distances
        vector<int> vis(N, 0); // visited array
        
        // Building the adjacency list
        for (auto edge : edges) {
            
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        
       stack<int>st;
       for(int i=0;i<N;i++)  //needed beacuse the gp may  have multiple components
       {
           if(!vis[i]) dfs(i,st,adj,vis);
       }
       ans[0]=0;
       while(!st.empty())
       {
           int top=st.top();
           int dist=ans[top];
           
           st.pop();
           for(auto node: adj[top])
           {   
               
               if(ans[node.first]>dist+node.second)
               {
                   ans[node.first]=dist+node.second;
               }

           }
       }
       for(int i=0;i<N;i++)
       {
           if(ans[i]==1e9) ans[i]=-1;
       }
       return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends