//User function template for C++

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){

    int V=matrix.size();
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(matrix[i][j]==-1)  //-1 means there is not an edge between i to j
                {   
                    matrix[i][j]=1e9;
                }
                if(i==j)matrix[i][j]=0;
            }
        }
    for(int src=0;src<V;src++)
    {  
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {

                    matrix[i][j]=min(matrix[i][j], matrix[i][src]+matrix[src][j]);
            }
        }
    }
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(matrix[i][j]==1e9)
                {   
                    matrix[i][j]=-1;
                }
            }
        }    
	}
};