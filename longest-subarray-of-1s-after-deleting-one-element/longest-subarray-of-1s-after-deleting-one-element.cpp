class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        int zeroCount=0;
        int start=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0) zeroCount+=1;
            while(zeroCount>1){
                zeroCount-=(nums[start]==0);
                start+=1;
            }
            ans=max(ans,i-start);
        }
        return ans;
    }
};

class dpSolution {
public:
    int ans;
    int dp[100001][2];
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        ans=0;
        memset(dp,-1,sizeof(dp));
        helper(0,nums,0);
        //if all are 1s, ignore single 1
        return ans==n?ans-1:ans;
    }

    int helper(int idx,vector<int>& nums,int deleted){
        if(idx==nums.size()) return 0;
        if(dp[idx][deleted]!=-1) return dp[idx][deleted];

        int cur=0;
        //if a number is already deleted
        if(deleted){
            //we will proceed only if num is 1, if 0 return 0 since we can't delete 2 nums
            if(nums[idx]==1){
                cur=1+helper(idx+1,nums,1);
                ans=max(ans,cur);
            }
        }
        //if nothing is deleted from the array
        else{
            if(nums[idx]==1){
                cur=1+helper(idx+1,nums,deleted);
                ans=max(ans,cur);
            }
            else{
                //ignore this zero, since we haven't deleted anything yet,takes care of the cases where 0s apprear in the beginning or at the end
                int ignore=helper(idx+1,nums,0);
                //delete the zero
                int del=helper(idx+1,nums,1);
                ans=max(ans,max(ignore,del));
                //make cur as deleted since that will help the previous recursion calls
                cur=del;
            }
        }
        return dp[idx][deleted]=cur;
    }
};