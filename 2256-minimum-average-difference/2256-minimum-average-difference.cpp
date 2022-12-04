class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        if(nums.size()==0) return 0;
        
        int n=nums.size();
    
        vector<long long> suffixSum(n,0);
        suffixSum[n-1]=nums[n-1];
        long long prefixSum=0;
        
        for(int i=n-2;i>=0;--i) suffixSum[i]=nums[i]+suffixSum[i+1];
        
        long long minn=INT_MAX;
        long long mini=-1;
        long long lAvg,rAvg,res;
        for(int i=0;i<n;++i){
            lAvg= (prefixSum+nums[i])/(i+1);
            rAvg=i+1<n?(suffixSum[i+1])/(n-i-1):0;
            res=abs(lAvg-rAvg);
            cout<<res<<endl;
            if(res<minn){
                minn=res;
                mini=i;
            }
            prefixSum+=nums[i];
            
        }
        
        return mini;
    }
};