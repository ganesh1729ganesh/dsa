#include <bits/stdc++.h>
using namespace std;

void divisibleby3(vector<int>arr,int k){
	
	int sum=0; bool found = false; pair<int,int>ans;
	
	for(int i=0;i<k;i++) sum+=arr[i];
	
	if(sum%3==0){
		found = true;
		ans=make_pair(0,k-1);
	}
	
   for(int i=k;i<arr.size();i++){
   	
   	if(found) break;
   	
   	sum = sum + arr[i] - arr[i-k];
   	
   	if(sum%3==0){
   		
   		ans = make_pair(i-k+1,i);
   		found = true;
   		
   	}
   	
   }
   
   if(!found) cout<<"No such value exists"<<endl;
   
   else{
   	
   	for(int i = ans.first;i<=ans.second;i++){
   		cout<<arr[i];
   	}
   	cout<<endl;
   	
   	
   }
	
}

int main() {
	// your code goes here
	
	vector<int> arr = {84,23,45,12,56,82};
	int k =3;
	divisibleby3(arr,k);
	return 0;
}