#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>

using namespace std;
class graph
{
  public:
        
        unordered_map<int,list<pair <int ,int> > > adj;

        void addEdge(int u,int v,int c)
        {   
            pair<int,int> p=make_pair(v,c);
            adj[u].push_back(p);
        }

        void Printgraph()
        {
            for(auto i:adj)
            {
                cout<<i.first<<" ->";
                for(auto j: i.second)
                {
                    cout<<"["<<j.first<<","<<j.second<<"]";
                }
                cout<<endl;
            }
        }
        void topo(int node,unordered_map<int ,bool> &visited,stack<int> &st)
        {
             visited[node]=true;
             for(auto neighbour: adj[node])
             {
                if(!visited[neighbour.first])
                {
                    topo(neighbour.first,visited,st);
                }
             }
             st.push(node);
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
      int u,v,c;
      cin>>u>>v>>c;
      p.addEdge(u,v,c);
    }
    p.Printgraph();
    unordered_map<int ,bool> visited;
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            p.topo(i,visited,st);
        }
    }
    
    int src;
    cout<<"enter source node\n";
    cin>>src;
    vector<int >dist(n,INT_MAX);
    dist[src]=0;

    while(!st.empty())
    {
        int front=st.top();
        st.pop();

        if(dist[front] !=INT_MAX)
        {
            for(auto i: p.adj[front])
            {
                if(i.second+dist[front] <dist[i.first])
                {
                    dist[i.first]=i.second+dist[front];
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<dist[i]<<" ";

    }
    cout<<endl;


return 0;
}
// 6
// 9
// 0 1 5
// 0 2 3
// 1 2 2
// 1 3 6
// 2 3 7
// 2 4 4
// 2 5 2
// 3 4 -1
// 4 5 -2