class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        //number and indices
        unordered_map<int,vector<int>> indices;
        for(int i=0;i<n;++i){
            indices[arr[i]].push_back(i);
        }
        vector<int> vis(n,0);
        int steps=0;
        queue<int> q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int len=q.size();
            while(len--){
                int cur=q.front();
                q.pop();
                if(cur==n-1) return steps;
                
                vector<int> &nextIndices=indices[arr[cur]];
                nextIndices.push_back(cur+1);
                nextIndices.push_back(cur-1);
                for(int ind:nextIndices){
                    if(ind>=0 && ind<n && !vis[ind]){
                        q.push(ind);
                        vis[ind]=1;
                    }
                }
                nextIndices.clear();
            }
            ++steps;
        }
        return -1;
    }
    
};