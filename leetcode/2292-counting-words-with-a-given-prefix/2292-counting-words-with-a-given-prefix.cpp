class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for (string& word : words) {
            if (pref.size() > word.size()) {
                continue;
            }

            bool isPref = true;
            for (int i = 0; i < pref.size(); ++i) {
                if (pref[i] != word[i]) {
                    isPref = false;
                    break;
                }
            }

            if (isPref) {
                ++ans;
            }
        }
        return ans;
    }
};