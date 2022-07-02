class Solution {
public:
    vector<vector<int>> ans;
    
    void generate(vector<int> &subset, int i, vector<int> &nums){
        if(i==nums.size()){
            ans.push_back(subset);
            return;
        }
        
        //ith element not included in the subset
        generate(subset,i+1,nums);
        
        //ith element included in the subset
        subset.push_back(nums[i]);
        generate(subset,i+1,nums);
        subset.pop_back();
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> emptySubset;
        generate(emptySubset,0,nums);
        
        return ans;
    }
};