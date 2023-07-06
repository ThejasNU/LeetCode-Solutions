class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(accumulate(nums.begin(),nums.end(),0)<target) return 0;
        long long l=0,r=nums.size();
        while(l<r){
            long long mid=(l+r)/2;
            if(subarrayPossible(mid,nums,target)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }

    bool subarrayPossible(long long size,vector<int>& nums,int target){
        long long sum=accumulate(nums.begin(),nums.begin()+size,0);
        if(sum>=target) return true;
        for(int i=size;i<nums.size();++i){
            sum-=nums[i-size];
            sum+=nums[i];
            if(sum>=target) return true;
        }
        return false;
    }
};