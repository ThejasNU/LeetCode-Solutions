class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 3) return false;
        
        sort(nums.begin(), nums.end());
        int close = nums[0] + nums[1] + nums[2];
        
        for(int i=0; i<n-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1;
            int k = n - 1;
            
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target)
                    return target;
                if(abs(target - sum) < abs(target - close))
                    close = sum;
                if(sum > target)
                    k--;
                else
                    j++;
            }
            
            
        }
        return close;
    }
};