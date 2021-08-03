vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
        // Code here
        const int inf = INT_MAX;
        vector<int> dist(V,inf);
        dist[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});//dist,node;
        
        while(!pq.empty()){
            int prev = pq.top().second;
            int dista = pq.top().first;
            pq.pop();
            
            for(auto it:adj[prev]){
                
                int currnode = it[0];
                int currdist = it[1];
                
                if(dist[prev]+currdist<dist[currnode]){
                    dist[currnode] = dist[prev]+currdist;
                    pq.push({dist[currnode],currnode});
                }
               
            }
        }
        
        return dist;
    }