#include <bits/stdc++.h>
using namespace std;

  int minSubArrayLen(int target, vector<int>& nums) {
        int left=0,right=0;
        long long int sum=0;
        int len=INT_MAX;
        bool flag=false;
        while(left <= right )
        {
            if(right >= nums.size() || left >= nums.size())
                break;
            if(sum+nums[right] >= target)
            {
                flag=true;
                len=min(len,right-left+1);
                sum-=nums[left];
                left++;
            }
            else if(sum+nums[right] < target)
            {
                sum+=nums[right];
                right++;
            }
        }
        if(flag==true)
            return len;
        else
            return 0;
        
    }

int main() {
	// your code goes here
	
	return 0;
}