class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        int ans=1;
        vector<int> children[n];
        
        for(int i=1;i<n;++i){
            children[parent[i]].push_back(i);
        }
        
        dfs(0,children,s,ans);
        return ans;
    }
    
    int dfs(int node,vector<int> children[],string &s,int &ans){
        int longestChain = 0, secondLongestChain = 0;
        
        for(int child:children[node]){
            int longestChainStartingFromChild = dfs(child, children, s,ans);
            if(s[child]==s[node]) continue;
            if (longestChainStartingFromChild > longestChain) {
                secondLongestChain = longestChain;
                longestChain = longestChainStartingFromChild;
            } 
            else if (longestChainStartingFromChild > secondLongestChain) {
                secondLongestChain = longestChainStartingFromChild;
            }
        }
        
        ans=max(ans,longestChain+secondLongestChain+1);
        return 1+longestChain;
    }
};