class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i=0;i<n;++i){
            if(manager[i]!=-1) adj[manager[i]].push_back(i);
        }
        queue<pair<int,int>> q;
        q.push({headID,0});
        int ans=INT_MIN;
        while(!q.empty()){
            int manager=q.front().first;
            int time=q.front().second;
            q.pop();
            ans=max(ans,time);
            for(int sub:adj[manager]){
                q.push({sub,time+informTime[manager]});
            }
        }
        return ans;
    }
};