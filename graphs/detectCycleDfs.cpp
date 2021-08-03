#include <iostream>
using namespace std;

 bool util(int node,int parent,vector<int>adj[],vector<int> &vis){
        vis[node]=1;
        
        for(auto i:adj[node]){
            
            if(!vis[i]){
                if(util(i,node,adj,vis)) return true;
            }
            else if(i!=parent) return true;
            
        }
        
       return false; 
    }
    
    
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<int> vis(V+1,0);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            if(util(i,-1,adj,vis)) return true;
	        }
	    }
	    	return false;
	}
	

int main() {
	// your code goes here
	return 0;
}