class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        int limit=(1<<n)-1;

        for(int bitMask=0;bitMask<=limit;++bitMask){
            int bitCount=__builtin_popcount(bitMask);
            if(bitCount!=k) continue;

            vector<int> temp;
            for(int i=0;i<n;++i){
                if(((bitMask>>i)&1)==1) temp.push_back(i+1);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

class backtrackingSolution {
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