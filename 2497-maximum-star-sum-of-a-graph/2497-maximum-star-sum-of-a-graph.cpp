class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n=vals.size();
        vector<int> adj[n];
        
        for(int i=0;i<edges.size();++i){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        int ans=INT_MIN;
        
        for(int i=0;i<n;++i){
            priority_queue<int> pq;
            for(int neighbour:adj[i]){
                pq.push(vals[neighbour]);
            }
            
            int curSum=vals[i];
            ans=max(ans,curSum);
            for(int j=0;j<k && !pq.empty();++j){
                int cur=pq.top();
                pq.pop();
                curSum+=cur;
                ans=max(ans,curSum);
            }
            
        }
        
        return ans;
    }
};