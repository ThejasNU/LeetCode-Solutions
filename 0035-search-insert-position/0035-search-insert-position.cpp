class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0;
        while(i<n && nums[i]<target) ++i;
        
        return i;
    }
};