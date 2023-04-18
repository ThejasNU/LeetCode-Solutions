class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int s1=word1.size();
        int s2=word2.size();
        int n=max(s1,s2);
        string ans="";
        for(int i=0;i<n;++i){
            if(i<s1) ans.push_back(word1[i]);
            if(i<s2) ans.push_back(word2[i]);
        }
        return ans;
    }
};