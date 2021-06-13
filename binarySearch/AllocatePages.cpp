#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPossible(int min,vector<int>arr,int m,int n){
    
    int students =1,sum=0;
    
    for(int i=0;i<n;i++){
        
        if(arr[i]>min) return false;
        
        if(sum+arr[i]>min){
            students++;
            sum = arr[i];
            
            if(students>m){
                return false;
            }
            
        }
        else sum+= arr[i];
        
        
    }
    
    
    return true;
    
}

int books(vector<int> A, int B) {
    
    int n = A.size();
    
    if(n<B) return -1;
    
    int sum=0;
    
    for(int i=0;i<n;i++) sum+=A[i];
    
    int left = 0,right = sum;
    int ans = INT_MAX;
    
    while(left<=right){
        
        int mid = left + (right-left)/2;
        
        if(isPossible(mid,A,B,n)){
            ans = min(ans,mid);
            right = mid-1;
        }
        else left = mid+1;
    }
    
    return ans;
    
}


int main() {
	// your code goes here
	return 0;
}