class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //indegree-outdegree==n-1 means judge
        vector<int> count(n+1,0);
        for(auto it:trust){
            count[it[0]]--;
            count[it[1]]++;
        }
        
        for(int i=1;i<=n;++i){
            if(count[i]==n-1) return i;
        }    
        
        return -1;
    }
};