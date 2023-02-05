class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1=s.size(),n2=p.size();
        vector<int> indexes;
        if(n1<n2) return indexes;
        
        vector<int> count1(26,0),count2(26,0);
        
        for(int i=0;i<n2;++i){
            count1[s[i]-'a']++;
            count2[p[i]-'a']++;
        }
        
        for(int i=0;i<n1-n2;++i){
            if(isEqual(count1,count2)) indexes.push_back(i);
            count1[s[i]-'a']--;
            count1[s[i+n2]-'a']++;
        }
        if(isEqual(count1,count2)) indexes.push_back(n1-n2);
        return indexes;
    }
    
    bool isEqual(vector<int> &count1,vector<int> &count2){
        for(int i=0;i<26;++i) if(count1[i]!=count2[i]) return false;
        return true;
    }
};