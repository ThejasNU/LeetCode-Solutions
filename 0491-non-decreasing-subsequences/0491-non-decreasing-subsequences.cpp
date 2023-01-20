class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        int n=(1<<nums.size());
        
        for(int bitMask=1;bitMask<n;++bitMask){
            vector<int> temp;
            
            for(int i=0;i<nums.size();++i){
                if((bitMask>>i)&1) temp.push_back(nums[i]);
            }
            
            bool isIncreasing=true;
            for(int i=1;i<temp.size();++i){
                isIncreasing&= temp[i-1]<=temp[i];
            }
            
            if(isIncreasing && temp.size()>1) ans.insert(temp);
        }
        
        return vector(ans.begin(),ans.end());
    }
};