class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> hasIncomingEdge(n,false);
        for(auto& edge:edges){
            hasIncomingEdge[edge[1]]=true;
        }
        vector<int> ans;
        for(int i=0;i<n;++i){
            if(!hasIncomingEdge[i]) ans.push_back(i);
        }
        return ans;
    }
};