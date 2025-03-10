class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        return atLeastK(word, k) - atLeastK(word, k + 1);
    }

private:
    long long atLeastK(string word, int k) {
        long long res = 0;
        int l = 0, r = 0;

        unordered_map<char, int> vowelCnt;
        int consonantCnt = 0;
        for (; r < word.size(); ++r) {
            if (isVowel(word[r])) {
                ++vowelCnt[word[r]];
            } else {
                ++consonantCnt;
            }

            for (; vowelCnt.size() == 5 && consonantCnt >= k; ++l) {
                res += word.size() - r;
                if (isVowel(word[l])) {
                    if (--vowelCnt[word[l]] == 0) {
                        vowelCnt.erase(word[l]);
                    }
                } else {
                    --consonantCnt;
                }
            }
        }

        return res;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};