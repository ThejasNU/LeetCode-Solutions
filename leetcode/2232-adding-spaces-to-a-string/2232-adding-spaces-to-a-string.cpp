class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans(s.size() + spaces.size(), ' ');
        int ansIdx = 0;
        int spaceIdx = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (spaceIdx < spaces.size() && i == spaces[spaceIdx]) {
                ++ansIdx;
                ++spaceIdx;
            }

            ans[ansIdx] = s[i];
            ++ansIdx;
        }
        return ans;
    }
};