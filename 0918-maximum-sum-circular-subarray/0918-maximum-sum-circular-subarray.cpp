class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curMax=0,curMin=0,sum=0,maxSum=nums[0],minSum=nums[0];
        
        for(int num:nums){
            curMax=max(curMax+num,num);
            curMin=min(curMin+num,num);
            
            maxSum=max(maxSum,curMax);
            minSum=min(minSum,curMin);
            
            sum+=num;
        }
        
        return sum==minSum?maxSum:max(maxSum,sum-minSum);
    }
};