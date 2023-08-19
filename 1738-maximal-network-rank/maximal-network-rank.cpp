class Solution {
public:
    //indegree of node1+indegree od node2-number ofcommon edges(because it should be counted once, it will contribute to indegree of both if it is common)
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int maxNetworkRank=0;
        vector<unordered_set<int>> adj(n);

        for(auto& edge:roads){
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }

        for(int node1=0;node1<n;++node1){
            for(int node2=node1+1;node2<n;++node2){
                int networkRank=adj[node1].size()+adj[node2].size();
                if(adj[node1].find(node2)!=adj[node1].end()){
                    networkRank-=1;
                }
                maxNetworkRank=max(maxNetworkRank,networkRank);
            }
        }
        return maxNetworkRank;
    }
};