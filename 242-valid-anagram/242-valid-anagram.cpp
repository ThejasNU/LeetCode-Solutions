class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> counter;
        if(s.size()!=t.size()){
            return false;
        }
        else{
            for(int i=0;i<s.size();++i){
                counter[s[i]]++;
            }
            for(int j=0; j<t.size();++j){
                if(counter[t[j]]==0){
                    return false;
                }
                counter[t[j]]--;
            }
            return true;
        }
        
        
    }
};