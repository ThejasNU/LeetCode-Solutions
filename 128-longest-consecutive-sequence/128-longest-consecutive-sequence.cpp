class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet;
        
        for(int num:nums){
            hashSet.insert(num);
        }
        
        int longestStreak=0;
        
        for(int num:nums){
            if(!hashSet.count(num-1)){
                int currentNum=num;
                int currentStreak=1;
                
                while(hashSet.count(currentNum+1)){
                    currentNum++;
                    currentStreak++;
                }
                
                longestStreak=max(currentStreak,longestStreak);
            }
        }
        
        return longestStreak;
    }
};