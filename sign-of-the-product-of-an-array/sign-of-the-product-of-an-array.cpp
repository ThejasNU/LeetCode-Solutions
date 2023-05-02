class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count=0,foundZero=0;
        for(int num:nums){
            if(num<0) ++count;
            else if(num==0){
                return 0;
            }
        }
        return (count&1?-1:1);
    }
};