#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int painterss(int arr[],int n,int limit){
	
	int sum=0,painters=1;
	
	for(int i=0;i<n;i++){
		sum+=arr[i];
		
		if(sum>limit){
			sum = arr[i];
			painters++;
		}
	}
	
	return painters;
	
}

int paintersPartition(int arr[],int n,int m){
	
	int k=0,sum=0;
	
	for(int i=0;i<n;i++){
		k = max(k,arr[i]);
		sum+= arr[i];
	}
	
	int start = k,end = sum;
	
	while(start<=end){
		int mid = (start+end)/2;
		
		int painters = painterss(arr,n,mid);
		
		if(painters<=m){
			end = mid-1;
		}
		else start = mid+1;
		
	}
	
	
	return start;
}

int main() {
	// your code goes here
	int arr[]={10,20,30,40};
	int n=4,m=2;
	cout<<paintersPartition(arr,n,m);
	return 0;
}