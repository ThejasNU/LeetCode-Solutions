class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int M=1e9+7;
        vector<pair<int,int>> adj[n];
        
        for(auto road:roads){
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }
        
        //distance,node
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        vector<long long> dist(n,LONG_MAX),ways(n,0);
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});
        
        while(!pq.empty()){
            long long cost=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                long long adjNode=it.first;
                long long wt=it.second;
                
                //reaching this node for the first time with shortest path
                if(cost+wt<dist[adjNode]){
                    dist[adjNode]=cost+wt;
                    pq.push({dist[adjNode],adjNode});
                    ways[adjNode]=ways[node]%M;
                }
                else if(cost+wt==dist[adjNode]){
                    ways[adjNode]+=ways[node];
                    ways[adjNode]%=M;
                }
            }
        }
        
        
        return ways[n-1];
    }
};