class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto it=nums.begin();
        
        while(it!=nums.end()){
            if(it+1==nums.end()){
                break;
            }
            if(*(it)==*(it+1)){
                nums.erase(it);
            }
            else{
                it++;
            }
        }
        return  nums.size();
    }
};