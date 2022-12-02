class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        
        for(int i=0;i<word1.size();++i){
            m1[word1[i]]++;
            m2[word2[i]]++;
        }
        
        //for storing frequencies
        unordered_map<int,int> m3;
        
        for(auto it:m1){
            if(!m2[it.first]) return false;
            
            m3[it.second]++;
        }
        
        for(auto it:m2){
            if(!m1[it.first]) return false;
            
            m3[it.second]--;
        }
        
        for(auto it:m3){
            if(it.second!=0) return false;
        }
        
        return true;
    }
};