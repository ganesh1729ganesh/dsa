#include <bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    
    bool util(int node,vector<int>adj[], vector<int> &vis){
        
        vis[node]=1;
        queue<pair<int,int>>q;
        q.push({node,-1});
        while(!q.empty()){
            
            int n = q.front().first;
            int par = q.front().second;
            q.pop();
            
            for(auto it:adj[n]){
                
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,n});
                }
                else if(it!=par) return true;
                
            }
            
        }
        return false;
        
    }
    
    
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int> vis(V+1,0);
	    bool cycle = false;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            if(util(i,adj,vis)) cycle = true;
	        }
	    }
	    
	    return cycle;
	}
};
int main() {
	// your code goes here
	
	return 0;
}