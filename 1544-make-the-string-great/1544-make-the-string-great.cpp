class Solution {
public:
    string makeGood(string s) {
        vector<char> st;

        for(int i=0;i<s.size();++i){
            if(!st.empty() && abs(st.back()-s[i])==32) st.pop_back();
            else st.push_back(s[i]);
        }
        
        string ans(st.begin(),st.end());
        return ans;
    }
};