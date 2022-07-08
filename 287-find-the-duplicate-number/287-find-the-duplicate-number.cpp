class Solution {
public:
    //hare tortoise algo
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        
        //finding the first collision to detect the cycle
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        
        //finding the repeating number
        fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        
        return fast;
    }
};