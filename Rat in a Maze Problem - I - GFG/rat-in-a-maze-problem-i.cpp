//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string temp="";
        vector<vector<int>> vis(n,vector<int> (n,0));

        if(m[0][0]) dfs(0,0,temp,m,ans,n,vis);
        return ans;
    }
    
    void dfs(int x,int y,string temp,vector<vector<int>> &m,vector<string> &ans,int n,vector<vector<int>> &vis){
        if(x==n-1 && y==n-1){
            ans.push_back(temp);
            return;
        }
        
        int dx[]={1,0,0,-1};
        int dy[]={0,-1,1,0};
        string direction="DLRU";
        
        for(int i=0;i<4;++i){
            int newX=x+dx[i];
            int newY=y+dy[i];
            
            if(newX<0 || newY<0 || newX>=n || newY>=n || m[newX][newY]==0 || vis[newX][newY]==1) continue;
            
            vis[x][y]=1;
            dfs(newX,newY,temp+direction[i],m,ans,n,vis);
            vis[x][y]=0;
        }
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends