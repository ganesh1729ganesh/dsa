#include <iostream>
#include<bits/stdc++.h>
using namespace std;

  int util(vector<int> arr,int key,int left,int right){
        
        if(left>right) return -1;
        
        int mid =  left + (right-left)/2;
        
        if(arr[mid]==key) return mid;
        
        if(arr[left]<=arr[mid]){
            
            if(arr[left]<=key and key<=arr[mid]) return util(arr,key,left,mid-1);
            
            
            return util(arr,key,mid+1,right);
            
            
        }
        
        
        if(arr[mid]<=key and key<=arr[right]) return util(arr,key,mid+1,right);
        
        
        return util(arr,key,left,mid-1);
        
        
    }
    
    int search(vector<int>& nums, int target) {
        
        return util(nums,target,0,nums.size()-1);
        
    }

int main() {
	// your code goes here
	return 0;
}