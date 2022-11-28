class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> m;
        
        for(int i=0;i<matches.size();++i){
            if(m.find(matches[i][0])==m.end()){
                m[matches[i][0]]=0;
            }
            m[matches[i][1]]++;
        }
        
        vector<vector<int>> ans={{},{}};
        
        for(auto it:m){
            if(it.second==0) ans[0].push_back(it.first);
            else if(it.second==1) ans[1].push_back(it.first);
        }
        
        return ans;
    }
};