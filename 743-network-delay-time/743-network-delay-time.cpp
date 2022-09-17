class Solution {
public:
    int dijkstra(int source,int n,vector<pair<int,int>> g[n]){
        vector<int> vis(n+1,0);
        vector<int> dist(n+1,INT_MAX);
        
        //{dist,vertex_no}
        set<pair<int,int>> st;
        st.insert({0,source});
        dist[source]=0;
        
        while(!st.empty()){
            auto node=*st.begin();
            int v=node.second;
            int v_dist=node.first;
            st.erase(st.begin());
            if(vis[v]) continue;
            vis[v]=1;
            for(auto child:g[v]){
                int child_v=child.first;
                int wt=child.second;
                
                if(v_dist+wt<dist[child_v]){
                    dist[child_v]=v_dist+wt;
                    st.insert({dist[child_v],child_v});
                }
            }
        }
        
        int res=0;
        for(int i=1;i<n+1;++i){
            if(dist[i]==INT_MAX) return -1;
            res=max(res,dist[i]);
        }
        return res;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //{vertex_no,weight}
        vector<pair<int,int>> g[n+1];
        for(auto vec:times){
            g[vec[0]].push_back({vec[1],vec[2]});
        }
        
        int ans=dijkstra(k,n,g);
        return ans;
        
    }
};