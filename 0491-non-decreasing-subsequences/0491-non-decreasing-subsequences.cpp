class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        set<vector<int>> ans;

        helper(0,nums,temp,ans);
        return vector(ans.begin(),ans.end());
    }
    
    void helper(int ind,vector<int> &nums,vector<int> &temp,set<vector<int>> &ans){
        if(ind==nums.size()){
            if(temp.size()>1) ans.insert(temp);
            return;
        }
        
        //not taking
        helper(ind+1,nums,temp,ans);
        
        //taking
        if(temp.size()==0 || temp.back()<=nums[ind]){
            temp.push_back(nums[ind]);
            helper(ind+1,nums,temp,ans);
            temp.pop_back();
        }
        
        return;
    }
};