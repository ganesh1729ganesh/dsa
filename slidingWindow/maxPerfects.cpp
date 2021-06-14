#include <bits/stdc++.h>
using namespace std;

bool isPerfectNumber(int n){
	
	int sum=1;
	
	for(int i=2;i<sqrt(n);i++){
		
		if(n%i==0){
			
			if(n/i==i) sum+=i;
			
			else sum+= (i+n/i);
			
		}
		
		
	}
	
	if(sum==n and n!=1) return true;
	
	return false;
	
	
}

int maxsum(vector<int>arr,int n,int k){
	
	if(n<k) return -1;
	
	int res=0;
	
	for(int i=0;i<k;i++) res+=arr[i];
	
	int sum = res;
	
	for(int i=k;i<n;i++){
		
		sum = sum+ arr[i] - arr[i-k];
		
		res = max(res,sum);
		
	}
	
	return res;
	
}

int maxNumberOfPerfects(vector<int>arr,int n,int k){
	
	for(int i=0;i<n;i++){
		
		if(isPerfectNumber(arr[i])) arr[i]=1;
		
		else arr[i] =0;
		
		
	}
	
	return maxsum(arr,n,k);
	
	
}

int main() {
	// your code goes here
	 vector<int>arr = {28,2,3,6,496,99,8128,24};
	
	cout<<maxNumberOfPerfects(arr,arr.size(),4);
	
	
	return 0;
}