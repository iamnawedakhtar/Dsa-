#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;
class graph
{
  public:
        
        unordered_map<int,list<int> > adj;
        void addEdge(int u,int v)
        {   
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        void Printgraph()
        {
            for(auto i:adj)
            {
                cout<<i.first<<" ->";
                for(auto j: i.second)
                {
                    cout<<"["<<j<<"]";
                }
                cout<<endl;
            }
        }
void dfs(int node ,int parent ,int &timer,vector<int> &disc,vector<int> &low,unordered_map<int ,bool> &visited,vector<int> &ans)
{    
      visited[node]=true;
      disc[node]=low[node]=timer++;
      int child=0;
      for(auto nbr: adj[node])
      {
        if(nbr==parent)
        continue;

         if(!visited[nbr])
        {        
               
               dfs(nbr,node,timer,disc,low,visited,ans);
               low[node]=min(low[nbr],low[node]);

               // check AP
               if(low[nbr]>=disc[node] && parent !=-1)
               {
                   ans.push_back(node);
               }
               child++;
        }
        else
        {
            //back edge
            low[node]=min(low[node],disc[nbr]);
        }
      }     
      if(parent==-1 && child>1)
      ans.push_back(node);
      cout<<child<<" "<<endl;
}
};

int main()
{ 
    int n,m;
    cout<< " enter nodes and edges \n";
    cin>>n>>m;

    graph p;
    for(int i=0;i<m;i++)
    {
      int u,v;
      cin>>u>>v;
      p.addEdge(u,v);
    }
    vector<int>ans;
    p.Printgraph();
    unordered_map<int ,bool> visited;
    vector<int>disc(n,-1);

    vector<int>low(n,-1);
    int parent =-1;
    
    int timer=0;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            p.dfs(i,parent,timer,disc,low,visited,ans);
        }
    }

for(int i=0;i<ans.size();i++)
{
    cout<<ans[i]<<" ";
}
cout<<endl;
return 0;
}
// 5 5
// 0 3
// 0 4
// 0 1
// 3 4
// 1 2