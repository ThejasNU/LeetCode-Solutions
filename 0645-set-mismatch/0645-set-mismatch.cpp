class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int dup=-1;
        int mis=1;
        
        for(int i=1;i<nums.size();++i){
            if(nums[i]==nums[i-1]) dup=nums[i];
            if(nums[i]>nums[i-1]+1) mis=nums[i-1]+1;
        }
        mis=nums[nums.size()-1]!=nums.size()?nums.size():mis;
        return {dup,mis};
    }
};