class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k==0) return nums;
        int n=nums.size();
        int windowSize=2*k+1;
        vector<int> ans(n,-1);
        if(n<windowSize) return ans;

        long long runningSum=0;
        int i;
        for(i=0;i<windowSize;++i) runningSum+=nums[i];
        ans[i-k-1]=runningSum/windowSize;
        cout<<i-k-1<<endl;
        for(;i<n;++i){
            runningSum-=nums[i-windowSize];
            runningSum+=nums[i];
            ans[i-k]=runningSum/windowSize;
        }
        return ans;
    }
};