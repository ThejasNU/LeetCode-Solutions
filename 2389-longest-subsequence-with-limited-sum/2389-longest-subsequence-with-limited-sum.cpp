class Solution {
public:
    //prefix sum+binary search
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();++i) nums[i]+=nums[i-1];
        
        vector<int> ans;
        //for each query,we need to find it's insertion position
        for(int query:queries){
            int index=upper_bound(nums.begin(),nums.end(),query)-nums.begin();
            ans.push_back(index);
        }
        
        return ans;
    }
};