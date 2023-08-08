class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;

        //make l point to the last element of the first increasing sub array
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]>nums[n-1]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }

        function<int(int,int)> binarySearch=[&](int l,int r){
            while(l<=r){
                int mid=(l+r)/2;
                if(nums[mid]>target){
                    r=mid-1;
                }
                else if(nums[mid]<target){
                    l=mid+1;
                }
                else{
                    return mid;
                }
            }
            return -1;
        };

        int index=binarySearch(0,l-1);
        if(index!=-1) 
            return index;
        else 
            return binarySearch(l,n-1);
    }
};