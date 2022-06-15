
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> hash;
        for(int i=0;i<nums.size();++i){
            hash[nums[i]]++;
            if(hash[nums[i]]>1){
                return true;
            }
        }
        return false;
        
    }
};