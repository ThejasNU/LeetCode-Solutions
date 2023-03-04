class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();        
        long long ans=0;
        int mini=-1,maxi=-1,leftBound=-1;
        
        for(int i=0;i<n;++i){
            if(nums[i]<minK || nums[i]>maxK) leftBound=i;
            
            if(nums[i]==minK) mini=i;
            if(nums[i]==maxK) maxi=i;
            
            ans+=max(0,min(maxi,mini)-leftBound);
        }
        
        return ans;
    }
};