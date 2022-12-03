class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> m;
        
        for(char c:s){
            m[c]++;
        }
        
        for(auto it:m){
            pq.push({it.second,it.first});
        }
        
        string ans="";
        while(!pq.empty()){
            auto cur=pq.top();
            pq.pop();
            
            for(int i=0;i<cur.first;++i){
                ans.push_back(cur.second);
            }
        }
        
        return ans;
    }
};