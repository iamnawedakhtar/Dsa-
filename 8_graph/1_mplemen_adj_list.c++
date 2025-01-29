#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;
class graph
{
  public:
        
        unordered_map<int,list<int>> adj;

        void addEdge(int u,int v,bool direction)
        {
       
               //0-> for undirected graph
               // 1-> for directed graph

            adj[u].push_back(v);
            if(direction==0)
            {
                adj[v].push_back(u);
            }   
        }

        void Printgraph()
        {
            for(auto i:adj)
            {
                cout<<i.first<<" ->";
                for(auto j: i.second)
                {
                    cout<<j<<", ";
                }
                cout<<endl;
            }
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
      p.addEdge(u,v,0);
    }
    p.Printgraph();

return 0;
}