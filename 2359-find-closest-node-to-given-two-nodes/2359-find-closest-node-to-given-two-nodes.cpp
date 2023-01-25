class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        
        vector<int> dist1(n,INT_MAX);
        vector<int> dist2(n,INT_MAX);
        vector<int> vis1(n,0);
        vector<int> vis2(n,0);
        
        dfs(node1,edges,dist1,vis1,0);
        dfs(node2,edges,dist2,vis2,0);
        
        int minDist=INT_MAX,minNode=-1;
        for(int i=0;i<n;++i){
            if(minDist>max(dist1[i],dist2[i])){
                minDist=max(dist1[i],dist2[i]);
                minNode=i;
            }
        }
        return minNode;
    }
    
    void dfs(int node,vector<int>& edges,vector<int> &dist,vector<int> &vis,int len){
        int next=edges[node];
        vis[node]=1;
        dist[node]=len;
        if(next!=-1 && !vis[next]) dfs(next,edges,dist,vis,len+1);
    }
};