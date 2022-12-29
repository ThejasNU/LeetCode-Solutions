//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<int> prev(n+1,-1);
        vector<int> dis(n+1,-1);
        
        vector<pair<int,int>> adj[n+1];
        
        for(auto edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dis[1]=0;
        pq.push({0,1});
        
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int wt=it.first;
            int node=it.second;
            
            for(auto edge:adj[node]){
                int neigh=edge.first;
                int w=edge.second;
                if(dis[neigh]==-1){
                    dis[neigh]=dis[node]+w;
                    prev[neigh]=node;
                    pq.push({dis[neigh],neigh});
                }
                else{
                    if(dis[neigh]>dis[node]+w){
                        dis[neigh]=dis[node]+w;
                        prev[neigh]=node;
                        pq.push({dis[neigh],neigh});
                    } 
                }
                
            }
        }
        
        if(prev[n]==-1) return {-1};
        
        vector<int> ans;
        int cur=n;
        while(cur!=1){
            ans.push_back(cur);
            cur=prev[cur];
        }
        ans.push_back(cur);
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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