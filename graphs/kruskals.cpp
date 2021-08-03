#include <iostream>
using namespace std;

	int findpar(int node, vector<int> &parent){
	    if(node==parent[node]) return node;
	    
	    return parent[node] = findpar(parent[node],parent);
	    
	}
	
	void unionn(int u,int v,vector<int>&parent,vector<int>&rank){
	    
	    u = findpar(u,parent);
	    v = findpar(v,parent);
	    
	    if(rank[u]<rank[v]) parent[u]=v;
	    else if(rank[v]<rank[u]) parent[v]=u;
	    else{
	       parent[v]=u;
	       rank[u]++;
	    }
	    
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<vector<int>>edges;
        
        for(int i=0;i<V;i++){
            vector<int>temp;
            for(auto j:adj[i]){
                
                temp.push_back(j[1]);
                temp.push_back(min(i,j[0]));
                temp.push_back(max(i,j[0]));
                
                 edges.push_back(temp);
                 temp.clear();
            }
            
        }
        
        sort(edges.begin(),edges.end());
        
        vector<int> parent(V), rank(V);
        
        for(int i=0;i<V;i++) parent[i]=i,rank[i]=0;
        
        int cost =0;
        
        for(auto it:edges){
            
            if(findpar(it[1],parent)!=findpar(it[2],parent)){
                cost+= it[0];
                unionn(it[1],it[2],parent,rank);
            }
            
        }
        
        return cost;
        
    }

int main() {
	// your code goes here
	return 0;
}