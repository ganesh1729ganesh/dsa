#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int arr[] = {1, 2, 2, 2, 3, 4, 5, 4, 7, 6, 5, 12};
	int k = 70;
	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	priority_queue<int> pq;
	
	for(int i=0;i<n;i++) pq.push(arr[i]);
	
	int sum=0;
	int cnt =0;
	
	while(!pq.empty()){
		sum+= pq.top();
		pq.pop();
		cnt++;
		
		if(sum>=k) break;
	}
	
	if(sum<k){
		cout<<-1;
		return 0;
	}
	
	cout<<cnt;
	return 0;
}