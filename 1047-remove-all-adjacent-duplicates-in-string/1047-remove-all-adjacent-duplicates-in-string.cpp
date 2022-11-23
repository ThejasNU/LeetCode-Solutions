class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> st;

        for(auto c:s){
            if(st.size()==0 || st.back()!=c){
                st.push_back(c);
            }
            else if(st.back()==c){
                st.pop_back();
            }
        }

        string res{st.begin(),st.end()};

        return res;
    }
};