DFS solution:

```cpp
class Solution {
public:
int findCircleNum(vector<vector<int>>& isConnected) {
    int n=isConnected.size();
    int count=0;
    vector<int> visited(n,0);
    for(int i=0;i<n;++i){
        if(!visited[i]){
        count++;
        dfs(i,visited,isConnected);
        }
    }
    return count;
}

private:
void dfs(int v,vector<int>& visited,vector<vector<int>>& isConnected){
    visited[v]=1;
    for(int i=0;i<isConnected[v].size();++i){
        if(isConnected[v][i]){
        if(i==v || visited[i]) continue;
        dfs(i,visited,isConnected);
        }
    }
}
};
```
