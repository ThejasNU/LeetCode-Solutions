class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        
        vector<vector<int>> diff(n,vector<int>(m,INT_MAX));
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        diff[0][0]=0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int d=it.first;
            int r=it.second.first;
            int c=it.second.second;
            
            if(r==n-1 && c==m-1) return d;
            
            for(int i=0;i<4;++i){
                int newr=r+dr[i];
                int newc=c+dc[i];
                
                if(newr>=0 && newc>=0 && newr<n && newc<m){
                    int newEffort= max(abs(heights[newr][newc]-heights[r][c]),d);
                    
                    if(newEffort<diff[newr][newc]){
                        diff[newr][newc]=newEffort;
                        pq.push({newEffort,{newr,newc}});
                    }
                }
            }

        }
        
        return -1;
        
    }
};