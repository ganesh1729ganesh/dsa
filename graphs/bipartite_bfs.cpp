#include <bits/stdc++.h>
using namespace std;


   bool util(int node,int color[], vector<int>adj[]){
       
       queue<int>q;
       q.push(node);
       
       color[node]=1;
       
       while(!q.empty()){
           int n = q.front();
           q.pop();
           
           for(auto i:adj[n]){
               
               if(color[i]==-1){
                   color[i]=1-color[n];
                   q.push(i);
               }
               else if(color[i]==color[n]) return false;
               
           }
           
       }
       
       
       
       return true;
       
   }


	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int color[V];
	    memset(color, -1, sizeof color); 
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(!util(i,color,adj)) return false;
	        }
	    }
	    
	    return true;
	}


int main() {
	// your code goes here
	return 0;
}