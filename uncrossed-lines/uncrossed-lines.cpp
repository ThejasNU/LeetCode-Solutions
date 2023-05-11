class Solution {
public:
    int dp[510][510];
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return helper(nums1,nums2,0,0);
    }

    int helper(vector<int>& nums1, vector<int>& nums2,int ind1,int ind2){
        if(ind1==nums1.size() || ind2==nums2.size()) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        
        if(nums1[ind1]==nums2[ind2]) dp[ind1][ind2]=1+helper(nums1,nums2,ind1+1,ind2+1);
        else dp[ind1][ind2]=max(helper(nums1,nums2,ind1,ind2+1),helper(nums1,nums2,ind1+1,ind2));
        
        return dp[ind1][ind2];
    }
};