class Solution {
public:
    string smallestNumber(string pattern) {
        stack<char> st;
        string ans = "";
        for (int i = 0; i <= pattern.size(); ++i) {
            st.push(i + 1 + '0');
            if (pattern[i] == 'I' || i == pattern.size()) {
                while (!st.empty()) {
                    ans.push_back(st.top());
                    st.pop();
                }
            }
        }
        return ans;
    }
};