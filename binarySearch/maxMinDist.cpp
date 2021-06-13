#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool isFeasible(int mid,int arr[],int n,int k){
	
	int pos = arr[0],eles =1;
	
	for(int i=1;i<n;i++){
		
		if(arr[i]-pos>=mid){
			pos = arr[i];
			eles++;
			if(eles==k) return true;
		}
		
		
	}
	
	return false;
	
}

int maxMinDist(int arr[],int n,int k){
	
	sort(arr,arr+n);
	
	int result =-1;
	
	int left =1,right = arr[n-1];
	
	while(left<right){
		
		int mid = (left+right)/2;
		
		if(isFeasible(mid,arr,n,k)){
			result = max(result,mid);
			left = mid+1;
		}
		else right = mid;
	}
	
	return result;
	
}

int main() {
	// your code goes here
	int arr[] = {1,2,8,4,9};
	int n = 5,k=3;
	cout<<maxMinDist(arr,n,k);
	return 0;
}