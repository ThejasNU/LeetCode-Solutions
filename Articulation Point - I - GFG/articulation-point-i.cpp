//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int timer;
    
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        timer=0;
        vector<int> vis(V,0);
        int tin[V];
        int low[V];
        
        vector<int> mark(V,0);
        
        for(int i=0;i<V;++i){
            if(!vis[i]) dfs(i,-1,vis,tin,low,mark,adj);
        }
        
        vector<int> ans;
        for(int i=0;i<V;++i){
            if(mark[i]==1) ans.push_back(i);
        }
        
        if(ans.size()==0) return {-1};
        else return ans;
    }
    
    void dfs(int node,int parent,vector<int> &vis,int tin[],int low[],vector<int> &mark,vector<int>adj[]){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        
        int child=0;
        for(auto it:adj[node]){
            if(it==parent) continue;
            
            if(vis[it]==0){
                dfs(it,node,vis,tin,low,mark,adj);
                low[node]=min(low[node],low[it]);
                
                //checking for articulation point
                if(low[it]>=tin[node] && parent!=-1){
                    mark[node]=1;
                }
                child++;
            }
            else{
                low[node]=min(low[node],tin[it]);
            }
        }
        
        if(child>1 && parent==-1) mark[node]=1;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends