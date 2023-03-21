class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        
        int i=0;
        while(i<n){
            if(nums[i]==0){
                long long count=1;
                ++i;
                while(i<n && nums[i]==nums[i-1]){
                    ++count;
                    ++i;
                }
                count*=count+1;
                count/=2;
                ans+=count;
            }
            else{
                ++i;
            }          
        }
        return ans;
    }
};