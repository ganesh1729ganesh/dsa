#include <iostream>
using namespace std;

	bool util(int node,vector<int> &vis,vector<int> &dfsvis,vector<int> adj[]){
	    
	    vis[node]=1;
	    dfsvis[node]=1;
	    
	    for(auto i:adj[node]){
	        
	        if(!vis[i]){
	            if(util(i,vis,dfsvis,adj)) return true;
	        }
	        else if(dfsvis[i]) return true;
	        
	    }
	    
	    dfsvis[node]=0;
	     return false;
	    
	    
	}
	
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	vector<int> vis(V,0),dfsvis(V,0);
	   	
	   	for(int i=0;i<V;i++){
	   	    
	   	    if(util(i,vis,dfsvis,adj)) return true;
	   	    
	   	}
	   	
	  return false; 	
	   	
	   	
	}


int main() {
	// your code goes here
	return 0;
}