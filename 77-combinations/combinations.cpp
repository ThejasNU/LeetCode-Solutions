class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        function<void(int)> helper=[&](int num)->void{
            if(num==n+1){
                if(temp.size()==k) ans.push_back(temp);
                return;
            }

            //ignore
            helper(num+1);

            //add
            temp.push_back(num);
            helper(num+1);
            temp.pop_back();
            
            return;
        };

        helper(1);
        return ans;
    }
};