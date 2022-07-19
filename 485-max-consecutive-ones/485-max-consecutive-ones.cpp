class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int maxCons=0;
        
        for(int i=0;i<nums.size();++i){
            if(nums[i]==1){
                count++;
                maxCons=max(count,maxCons);
            }
            else{
                count=0;
            }
        }
        
        return maxCons;
    }
};