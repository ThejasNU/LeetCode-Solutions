class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;

        function<void(int,vector<int>&,int)> helper=[&](int idx,vector<int>& temp,int sum){
            if(idx==n){
                if(sum==target){
                    ans.push_back(temp);
                }
                return;
            }

            //ignore
            helper(idx+1,temp,sum);
            //add
            if(candidates[idx]+sum<=target){
                temp.push_back(candidates[idx]);
                helper(idx,temp,sum+candidates[idx]);
                temp.pop_back();
            }
        };
        helper(0,temp,0);
        return ans;
    }
};