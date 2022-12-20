class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        
        vector<int> vis(n,0);
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            vis[cur]=1;
            
            for(int v:rooms[cur]){
                if(!vis[v]) q.push(v);
            }
        }
        
        for(int yn:vis){
            if(!yn) return false;
        }
        
        return true;
    }
};