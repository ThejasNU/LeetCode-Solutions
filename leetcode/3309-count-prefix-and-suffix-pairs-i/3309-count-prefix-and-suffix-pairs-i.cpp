class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (words[i].size() > words[j].size()) {
                    continue;
                }

                if (isPrefix(words[i], words[j]) &&
                    isSuffix(words[i], words[j])) {
                    ++ans;
                }
            }
        }
        return ans;
    }

private:
    bool isPrefix(const string& s1, const string& s2) {
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                return false;
            }
        }
        return true;
    }

    bool isSuffix(const string& s1, const string& s2) {
        int i = s1.size() - 1;
        int j = s2.size() - 1;
        while (i >= 0) {
            if (s1[i] != s2[j]) {
                return false;
            }
            --i;
            --j;
        }
        return true;
    }
};