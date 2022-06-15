class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> hash;
        for(int i=0;i<nums.size();++i){
            hash[nums[i]]++;
        }
        int sol;
        for(int j=0;j<nums.size();++j){
            if(hash[nums[j]]==1){
                sol=nums[j];
            }
        }
        return sol;
    }
};