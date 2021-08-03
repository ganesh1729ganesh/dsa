#include <iostream>
using namespace std;

  int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int parent[V];
        int mst[V];
        int key[V];
        
        for(int i=0;i<V;i++){
            mst[i]=0;
            key[i]=INT_MAX;
            parent[i]=-1;
        }
        
        key[0]=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        pq.push({0,0});
        //key,node
        
        while(!pq.empty()){
            
            int u = pq.top().second;
            pq.pop();
             mst[u]=1;
            for(auto i:adj[u]){
                
                int v = i[0];
                int w = i[1];
                
                if(!mst[v] and w<key[v]){
                   
                    parent[v]=u;
                    key[v]=w;
                    pq.push({key[v],v});
                }
                
                
            }
            
            
        }
        int cost=0;
        for(int i=0;i<V;i++) cost+=key[i];
        
        return cost;
    }

int main() {
	// your code goes here
	return 0;
}