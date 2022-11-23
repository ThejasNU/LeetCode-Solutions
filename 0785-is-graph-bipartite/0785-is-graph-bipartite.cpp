class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        queue<int> q;

        for(int v=0;v<n;++v){
            if(color[v]==-1){
                bool res=colorComponent(v,graph,color,q,n);
                if(!res) return false;
            }
        }
        
        return true;
    }

    bool colorComponent(int v,vector<vector<int>>& graph,vector<int> &color,queue<int> &q,int n){
        q.push(v);
        color[v]=0;

        while(!q.empty()){
            int cur=q.front();
            q.pop();

            for(int i:graph[cur]){
                if(color[i]==-1){
                    color[i]=!color[cur];
                    q.push(i);
                }
                else{
                    if(color[i]==color[cur]) return false;
                }
                
            }
        }

        return true;
    }
};