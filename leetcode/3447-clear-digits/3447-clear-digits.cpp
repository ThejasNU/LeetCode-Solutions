class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for (char c : s) {
            if (isdigit(c)) {
                st.pop();
            } else {
                st.push(c);
            }
        }

        int n = st.size();
        string ans(n, ' ');
        for (int i = n - 1; i >= 0; --i) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};