class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum=0,tempSum=0;
        unordered_map<int,int> m;
        int i;
        
        for(i=0;i<k;++i){
            m[nums[i]]++;
            tempSum+=nums[i];
        }
        if(m.size()==k) maxSum=tempSum;
        
        while(i<nums.size()){
            m[nums[i]]++;
            m[nums[i-k]]--;
            if(m[nums[i-k]]==0) m.erase(nums[i-k]);

            tempSum+=nums[i];
            tempSum-=nums[i-k];
            if(m.size()==k) maxSum=max(maxSum,tempSum);
            ++i;
        }

        return maxSum;
    }
};