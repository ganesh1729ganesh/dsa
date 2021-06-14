#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int num){
	
	string s = to_string(num);
	
	string temp=s;
	
	reverse(temp.begin(),temp.end());
	
	if(s.compare(temp)==0) return true;
	
	return false;
}

int palindromicConcatenation(vector<int>arr,int k){
	
	int num =0;
	
	int n = arr.size();
	
	for(int i=0;i<k;i++){
		
		num = num*10+arr[i];
	}
	
	if(isPalindrome(num)) return 0;
	
	for(int i =k;i<n;i++){
		
		num = (num%(int)pow(10,k-1))*10+arr[i];
		
		if(isPalindrome(num)) return i-k+1;
	}
	
	return -1;
	
}

int main() {
	// your code goes here
	vector<int>arr = {2,3,5,1,1,5};
	int k=4;
	int p = palindromicConcatenation(arr,k);
	
	if(p==-1){
		cout<<"palindrome not found"<<endl;
	}
	
	else{
		for(int i=p;i<p+k;i++) cout<<arr[i];
	}
	cout<<endl;
	
	return 0;
}