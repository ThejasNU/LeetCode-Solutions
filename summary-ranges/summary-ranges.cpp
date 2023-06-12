class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string> ans;
        int i=0;
        while(i<n){
            int begin=nums[i];
            while(i+1<n && nums[i+1]==nums[i]+1) ++i;
            if(begin==nums[i]) ans.push_back(to_string(begin));
            else ans.push_back(to_string(begin)+"->"+to_string(nums[i]));
            ++i; 
        }
        return ans;
    }
};