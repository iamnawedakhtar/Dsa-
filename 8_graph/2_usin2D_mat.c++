#include<iostream>
#include<vector>
using namespace std;
void buildGraph(int u,int v,bool direction ,vector<vector<int> > &mat)
{
    mat[u][v]=1;

    //direction=1 means undirected
    //direction =0 meand directed
    if(direction)
    {
      mat[v][u]=1;
    }
}

void print(vector<vector<int> > &mat)
{
    for(int i=1;i<mat.size();i++)
    {    
        cout<<i<<" -> ";
        for(int j=1;j<mat.size();j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{ 
    int n,m;
    cout<< " enter nodes and edges \n";
    cin>>n>>m;

    vector<vector<int> >mat(n+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        buildGraph(u,v,0,mat);
    }
    print(mat);
    
return 0;
}