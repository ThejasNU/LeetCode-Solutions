class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.size(), m = part.size();
        stack<char> st;
        for (int i = 0; i < n; ++i) {
            st.push(s[i]);
            if (st.size() >= m && isPresent(st, part, m)) {
                for (int j = 0; j < m; ++j) {
                    st.pop();
                }
            }
        }
        string ans(st.size(), ' ');
        for (int i = st.size() - 1; i >= 0; --i) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }

private:
    bool isPresent(stack<char>& st, const string& part, int m) {
        stack<char> temp = st;
        for (int i = m - 1; i >= 0; --i) {
            if (temp.top() != part[i]) {
                return false;
            }
            temp.pop();
        }
        return true;
    }
};