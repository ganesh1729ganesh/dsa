#include <iostream>
using namespace std;

	void dfs(int node,vector<int> &vis,stack<int> &sta,vector<int> adj[]){
	    
	    vis[node]=1;
	    
	    for(auto it:adj[node]){
	        
	        if(!vis[it]){
	            dfs(it,vis,sta,adj);
	        }
	        
	    }
	    
	    sta.push(node);
	    
	}
	
	
	
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>res;
	    vector<int> vis(V,0);
	    stack<int> sta;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,vis,sta,adj);
	        }
	    }
	    while(!sta.empty()){
	        res.push_back(sta.top());
	        sta.pop();
	    } 
	    return res;
	}


int main() {
	// your code goes here
	return 0;
}