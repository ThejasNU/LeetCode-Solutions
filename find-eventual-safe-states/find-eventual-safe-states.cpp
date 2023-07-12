class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> outdegree(n,0);
        vector<int> from[n];
        queue<int> q;
        for(int i=0;i<n;++i){
            outdegree[i]=graph[i].size();
            if(outdegree[i]==0) q.push(i);
            for(int node:graph[i]){
                from[node].push_back(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            ans.push_back(cur);
            
            for(int node:from[cur]){
                outdegree[node]-=1;
                if(outdegree[node]==0) q.push(node);
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }

};