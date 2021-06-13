#include <bits/stdc++.h>
using namespace std;

int util(vector<int>arr,int n,int left,int right){
        
        int mid = (left) + (right-left)/2;
        
        if((mid==0 or arr[mid-1]<=arr[mid]) and (mid==n-1 or arr[mid]>=arr[mid+1])) return mid;
        
        else if(mid>0 and arr[mid-1]>=arr[mid]) return util(arr,n,left,mid-1);
        
        else return util(arr,n,mid+1,right);
    }
    
    int findPeakElement(vector<int>& nums) {
        
        return util(nums,nums.size(),0,nums.size()-1);
        
    }

int main() {
	// your code goes here
	return 0;
}