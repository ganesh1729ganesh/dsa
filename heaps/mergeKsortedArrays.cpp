#include <bits/stdc++.h>
using namespace std;

int main() {
	
	vector<vector<int>> arr = {{1,2,3},{-1,45,90},{4,23,42,56}};
	int k=3;

        vector<int>idx(k,0);
        vector<int>res;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        for(int i=0;i<k;i++) pq.push({arr[i][0],i});
        
        while(!pq.empty()){
            pair<int,int> x = pq.top();
             pq.pop();
            res.push_back(x.first);
           
            if(idx[x.second]+1<arr[x.second].size()){
                pq.push({arr[x.second][idx[x.second]+1],x.second});
            }
            
            idx[x.second]+=1;
            
        }
        
        for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
	
	
	
	
	return 0;
}