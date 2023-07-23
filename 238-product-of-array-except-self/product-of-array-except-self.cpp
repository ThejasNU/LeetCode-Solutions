class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,1);

        int prefixProd=1,sufixProd=1;
        for(int i=0;i<n;++i){
            ans[i]*=prefixProd;
            prefixProd*=nums[i];
            ans[n-1-i]*=sufixProd;
            sufixProd*=nums[n-1-i];
        }
        return ans;
    }
};