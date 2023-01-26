class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto route:flights){
            adj[route[0]].push_back({route[1],route[2]});
        }
        vector<int> dis(n,INT_MAX);
        dis[src]=0;
        
        //stops,node,distance
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            
            if(stops>k) continue;
            
            for(auto edge:adj[node]){
                int neigh=edge.first;
                int wt=edge.second;
                
                //stops can be equal to k as well coz level k node can also update the weight
                if(cost+wt<dis[neigh] && stops<=k){
                    dis[neigh]=cost+wt;
                    q.push({stops+1,{neigh,dis[neigh]}});
                }
            }
        }
        return (dis[dst]==INT_MAX?-1:dis[dst]);
    }
};