//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        //neighbour,distance
        vector<pair<int,int>> adj[N];
        vector<int> vis(N,0);
        stack<int> st;
        vector<int> dis(N,-1);
        dis[0]=0;
        
        for(auto edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        
        dfs(0,adj,vis,st);
        
        while(!st.empty()){
            int cur=st.top();
            st.pop();
            
            for(auto neighbor:adj[cur]){
                int newDist=dis[cur]+neighbor.second;
                if(dis[neighbor.first]==-1){
                    dis[neighbor.first]=newDist;
                }
                else{
                    if(dis[neighbor.first]>newDist){
                        dis[neighbor.first]=newDist;
                    }
                }
            }
        }
        
        return dis;
    }
    
    void dfs(int node,vector<pair<int,int>> adj[],vector<int> &vis,stack<int> &st){
        vis[node]=1;
        for(auto neighbor:adj[node]){
            if(!vis[neighbor.first]) dfs(neighbor.first,adj,vis,st);
        }
        
        st.push(node);
        return;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends