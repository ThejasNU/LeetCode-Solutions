class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int len=nums.size();
        for(int i=0;i<len;++i){
            nums.push_back(nums[i]);
        }
        return nums;
    }
};