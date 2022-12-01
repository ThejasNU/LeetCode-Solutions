class Solution {
public:
    bool halvesAreAlike(string s) {
        int c1=0,c2=0;
        
        int n=s.size();
        int h=n/2;
        unordered_set<char> st={'a','e','i','o','u','A','E','I','O','U'};
        
        for(int i=0;i<h;++i){
            if(st.find(s[i])!=st.end()) c1++;
            if(st.find(s[i+h])!=st.end()) c2++;
        }
        
        return c1==c2;
    }
};