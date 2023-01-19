class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int prefixMod=0,ans=0;
        
        vector<int> modGroups(k,0);
        modGroups[0]=1;
        
        for(int num:nums){
            prefixMod=(prefixMod+num % k + k)%k;
            ans+=modGroups[prefixMod];
            modGroups[prefixMod]++;
        }
        
        return ans;
    }
};