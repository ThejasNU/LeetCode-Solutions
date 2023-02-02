class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> m;
        for(int i=0;i<order.size();++i){
            m[order[i]]=i;
        }
        
        for(int i=1;i<words.size();++i){
            for(int j=0;j<words[i-1].size();++j){
                if(j>=words[i].size()) return false;
                if(words[i-1][j]!=words[i][j]){
                    if(m[words[i-1][j]]>m[words[i][j]]) return false;
                    else break;
                }
            }
        }
        return true;
    }
};