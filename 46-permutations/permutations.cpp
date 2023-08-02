class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> taken(n,0);

        function<void()> helper=[&]()->void{
            if(temp.size()==n){
                ans.push_back(temp);
                return;
            }

            for(int i=0;i<n;++i){
                if(!taken[i]){
                    taken[i]=1;
                    temp.push_back(nums[i]);
                    helper();
                    temp.pop_back();
                    taken[i]=0;
                }
            }
        };

        helper();
        return ans;
    }
};