class Solution {
public:
    
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int,int> dp;
        sort(nums.begin(),nums.end());
        int ans=0;
        
        int temp;
        for(int n:nums){
            temp=sqrt(n);
            
            if(temp*temp==n){
                dp[n]=1+dp[temp];
            }
            else{
                dp[n]=1;
            }
            
            ans=max(ans,dp[n]);
        }
        
        return ans<2?-1:ans;
    }
};