class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> ans;
        int i=0;
        while(i<n-2){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>0){
                    while(j<k && nums[k]==nums[k-1]) --k;
                    --k;
                }
                else if(sum<0){
                    while(j<k && nums[j]==nums[j+1]) ++j;
                    ++j;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[k]==nums[k-1]) --k;
                    while(j<k && nums[j]==nums[j+1]) ++j;
                    ++j;--k;
                }
            }
            while(i<n-2 && nums[i]==nums[i+1]) ++i;
            ++i;
        }
        return ans;
    }
};