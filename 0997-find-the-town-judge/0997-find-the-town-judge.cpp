class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //indegree-outdegree==n-1 means judge
        vector<int> balance(n+1,0);
        for(auto it:trust){
            balance[it[0]]--;
            balance[it[1]]++;
        }
        
        for(int i=1;i<=n;++i) if(balance[i]==n-1) return i;  
        
        return -1;
    }
};