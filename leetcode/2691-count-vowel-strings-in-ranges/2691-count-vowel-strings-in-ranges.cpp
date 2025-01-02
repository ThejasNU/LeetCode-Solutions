class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<int> prefix(words.size(), 0);
        prefix[0] = (isVowel(words[0].front()) && isVowel(words[0].back()));

        for (int i = 1; i < words.size(); ++i) {
            prefix[i] = prefix[i - 1] +
                        (isVowel(words[i].front()) && isVowel(words[i].back()));
        }

        vector<int> ans;
        for (auto& query : queries) {
            if (query[0] == 0) {
                ans.push_back(prefix[query[1]]);
            } else {
                ans.push_back(prefix[query[1]] - prefix[query[0] - 1]);
            }
        }

        return ans;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};