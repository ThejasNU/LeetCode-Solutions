class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        
        if(word[0]>='A' && word[0]<='Z'){
            if(n>1 && word[1]>='A' && word[1]<='Z'){
                for(int i=2;i<n;++i) if(word[i]<'A' || word[i]>'Z') return false;
            }
            else{
                for(int i=2;i<n;++i) if(word[i]>='A' && word[i]<='Z') return false;
            }
        }
        else{
            for(int i=1;i<n;++i) if(word[i]>='A' && word[i]<='Z') return false;
        }
        
        return true;
    }
};