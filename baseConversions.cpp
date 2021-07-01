#include <bits/stdc++.h>
using namespace std;

int hexaToDec(string s){
	
	int n = s.size();
	
	int ans =0;
	int x =1;
	for(int i=n-1;i>=0;i--){
		
		if(s[i]>='0' and s[i]<='9'){
			ans+= x*(s[i]-'0');
		}
		else if(s[i]>='A' and s[i]<='F'){
			ans += x*(s[i]-'A'+10);
		}
		
		x*=16;
		
	}
	
	
	return ans;
}

int decToBin(int n){
	
	int x=1;
	int ans =0;
	
	while(x<=n) x*=2;
	x/=2;
	
	while(x>0){
		
		int ld = n/x;
		n -= ld*x;
		x/=2;
		ans = ans *10+ld;
		
	}
	
	return ans;
	
}

string decTohex(int n){
	
	string ans ="";
	int x =1;
	
	while(x<=n) x*=16;
	x/=16;
	
	while(x>0){
		
		int ld = n/x;
		n-= ld*x;
		x/=16;
		
		if(ld<=9){
			ans = ans + to_string(ld);
		}
		else{
			char c = 'A'+ld-10;
			ans.push_back(c);
		}
		
		
		
	}
	
	return ans;
	
}

int main() {
	// your code goes here
	
   string s;
   cin>>s;
   
   cout<<hexaToDec(s)<<" ";
   cout<<decTohex(463)<<" ";
   
   int n = 10;
   cout<<decToBin(n);
	
	return 0;
}