class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int ans = 0;
        helper(0, s, st, ans);
        return ans;
    }

    void helper(int idx, const string& s, unordered_set<string>& st, int& ans) {
        if (st.size() + s.size() - idx <= ans) {
            return;
        }

        if (idx == s.size()) {
            ans = max(ans, int(st.size()));
            return;
        }

        for (int end = idx; end < s.size(); ++end) {
            string subStr = s.substr(idx, end - idx + 1);
            if (st.find(subStr) == st.end()) {
                st.insert(subStr);
                helper(end + 1, s, st, ans);
                st.erase(subStr);
            }
        }
    }
};