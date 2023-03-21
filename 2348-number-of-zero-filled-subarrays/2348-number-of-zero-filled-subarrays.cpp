class Solution{
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        long long subArrayNumsCount=0;
        for(int num:nums){
            if(num==0) ++subArrayNumsCount;
            else subArrayNumsCount=0;
            ans+=subArrayNumsCount;
        }
        return ans;
    }
};

class shittySolution {
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
                //sum of first n natural numbers
                //1 0s->1
                //2 0s->1+2
                //3 0s->1+2+3
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