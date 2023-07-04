class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int once=0;
        int twice=0;

        for(int num:nums){
            //ignore the number which has already appreared twice (so that 3rd apprearance will be ignored and it becomes "Single Number" question)
            once^=(num & ~twice);
            //xor to remove duplicates since we have ignored the 3rd appearance
            //don't consider if the number has appreared only once
            twice^=(num & ~once);
        }
        return once;
    }
};