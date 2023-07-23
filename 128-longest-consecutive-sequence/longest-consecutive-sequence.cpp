class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int ans=0;
        int curNum,curCount;
        for(int num:nums){
            if(s.find(num-1)!=s.end()) continue;

            curNum=num;
            curCount=1;
            while(s.find(curNum+1)!=s.end()){
                curNum+=1;
                curCount+=1;
            }
            ans=max(ans,curCount);
        }
        return ans;
    }
};