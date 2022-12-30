class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        dfs(0,graph,ans,temp);
        return ans;
    }
    
    void dfs(int node,vector<vector<int>>& graph,vector<vector<int>>& ans,vector<int> &temp){
        temp.push_back(node);
        if(node==graph.size()-1){
            ans.push_back(temp);
        }
        else{
            for(int neigh:graph[node]){
                dfs(neigh,graph,ans,temp);
            }
        }
        temp.pop_back();
    }
};