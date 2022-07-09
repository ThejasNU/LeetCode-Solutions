class Solution {
public:
    
    //kadane's algo
    //if sum is <0 make it 0 and move next, if the sum is positive and next if a negative number appears and if the sum is still >0, include that also
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maximum=INT_MIN;
        
        for(auto it:nums){
            sum+=it;
            maximum=max(sum,maximum);
            if(sum<0) sum=0;
        }
        
        return maximum;
    }
};