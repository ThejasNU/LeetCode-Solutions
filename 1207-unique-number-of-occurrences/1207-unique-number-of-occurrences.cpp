class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        
        for(int n:arr){
            m[n]++;
        }
        
        unordered_set<int> s;
        
        for(auto it:m){
            s.insert(it.second);
        }
        
        return s.size()==m.size();
    }
};