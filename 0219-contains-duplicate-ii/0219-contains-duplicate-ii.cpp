class Solution {
public:
    
    //maintain k+1 elements in set
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k==0 || nums.size()<2) return false;
        
        set<int> s;
        
        for(int i=0;i<nums.size();++i){
            if(i>k){
                auto it=s.find(nums[i-k-1]);
                s.erase(it);
            }
            
            if(s.find(nums[i])!=s.end()) return true;
            else s.insert(nums[i]);
        }
        
        return false;
    }
};