class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count=0,foundZero=0;
        for(int num:nums){
            if(num<0) ++count;
            else if(num==0){
                foundZero=1;
                break;
            }
        }
        if(foundZero) return 0;
        else return (count&1?-1:1);
    }
};