
// topo sort use nhi kar sakte (dfs wala) to detect cycle in a directed graph but can use kahn's algo 
#include <bits/stdc++.h>
using namespace std;


// using stack and the topo approach  (this is a wrong method as it will not detect cycle , this method can only be use to print topo order in DAG)
class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	
     bool iscycle(int node, vector<bool> & vis, vector<bool> &recstack, vector<int> adj[])
    {
        vis[node]=1;
        recstack[node]=1;

        for(auto adjnode: adj[node])
        {
            if(!vis[adjnode])
            {
                if(iscycle(adjnode,vis,recstack,adj)) return true;
            }
            else
            {
                if(recstack[adjnode]) return true;
            }
        }

        recstack[node]=false;
        return false;
    }
	bool canFinish(int V, vector<vector<int>>& graph) {
        
        vector<int> adj[V];
        for(auto it:graph )
        {
            int v=it[0];
            int u=it[1];

            adj[u].push_back(v);
        }

        vector<bool>vis(V,0);
        vector<bool>recstack(V,0);

        for(int i=0;i<V;i++){

            if(iscycle(i,vis,recstack,adj)) return true; //cycle exixt 
        }

        return false; // cycle does not exist
    }
};

// using bfs approach (khan's algortithm)

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
  

		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		return !(topo.size()==V);
    }
};