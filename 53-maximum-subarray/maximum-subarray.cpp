class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN;
        int curSum=0;
        for(int num:nums){
            curSum+=num;
            maxSum=max(maxSum,curSum);
            if(curSum<0) curSum=0;
        }
        return maxSum;
    }
};