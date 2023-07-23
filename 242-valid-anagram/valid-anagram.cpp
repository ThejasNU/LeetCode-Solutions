class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int countS[26]={0};
        int countT[26]={0};

        for(int i=0;i<s.size();++i){
            countS[s[i]-'a']+=1;
            countT[t[i]-'a']+=1;
        }

        for(int i=0;i<26;++i){
            if(countS[i]!=countT[i]) return false;
        }
        return true;
    }
};