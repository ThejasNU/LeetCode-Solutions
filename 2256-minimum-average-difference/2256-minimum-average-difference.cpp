class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        if(nums.size()==0) return 0;
        
        int n=nums.size();
    
        long long prefixSum=0;
        long long totalSum=0;  
        
        for(int i=0;i<n;++i) totalSum+=nums[i];
        
        long long minn=INT_MAX;
        long long mini=-1;
        long long lAvg,rAvg,res;
        
        for(int i=0;i<n;++i){
            prefixSum+=nums[i];
            lAvg= (prefixSum)/(i+1);
            rAvg=i+1<n?(totalSum-prefixSum)/(n-i-1):0;
            res=abs(lAvg-rAvg);
            cout<<res<<endl;
            if(res<minn){
                minn=res;
                mini=i;
            }
        }
        
        return mini;
    }
};