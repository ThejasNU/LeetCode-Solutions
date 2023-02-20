class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        
        if(nums[0]>=target) return 0;
        else if(nums[n-1]<target) return n;
        
        int l=0,r=n-1;
        while(l<r){
            int mid= l+((r-l)/2);
            
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) l=mid+1;
            else r=mid;
        }
        return l;
    }
};


class linearSolution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0;
        while(i<n && nums[i]<target) ++i;
        return i;
    }
};