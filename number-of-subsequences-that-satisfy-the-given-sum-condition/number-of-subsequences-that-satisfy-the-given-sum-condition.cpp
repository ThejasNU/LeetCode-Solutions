class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        int M=1e9+7;
        int l=0,r=n-1;

        vector<int> power(n);
        power[0]=1;
        for(int i=1;i<n;++i){
            power[i]=(power[i-1]*2)%M;
        }
        
        while(l<=r){
            if(nums[l]+nums[r]<=target){
                ans+=power[r-l];
                ans%=M;
                ++l;
            }
            else{
                --r;
            }
        }
        return ans;
    }
};