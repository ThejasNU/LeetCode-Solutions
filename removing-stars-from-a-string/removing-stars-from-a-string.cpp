class p2Solution {
public:
    string removeStars(string s) {
        int j=0;
        int n=s.size();
        for(int i=0;i<n;++i){
            if(s[i]=='*') --j;
            else s[j++]=s[i];
        }
        return s.substr(0,j);
    }
};

class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int n=s.size();
        for(int i=0;i<n;++i){
            if(s[i]=='*') st.pop();
            else st.push(s[i]);
        }
        string ans = "";
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

class noobSolution {
public:
    string removeStars(string s) {
        int start=0,main=0,i=0;
        int n=s.size();
        
        while(i<n){
            while(i<n && s[i]!='*') ++i;
            int starsCount=0;
            while(i<n && s[i]=='*'){
                ++starsCount;
                ++i;
            }
            int numChars=i-start-starsCount;
            int charsToAdd=numChars-starsCount;
            if(numChars<starsCount){
                int dif=starsCount-numChars;
                main-=dif;
            }
            while(charsToAdd>0){
                s[main]=s[start];
                ++main;
                ++start;
                --charsToAdd;
            }
            start=i;
        }
        return s.substr(0,main);
    }
};