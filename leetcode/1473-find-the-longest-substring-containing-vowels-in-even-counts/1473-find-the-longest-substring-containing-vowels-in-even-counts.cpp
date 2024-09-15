class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char, int> vowelMap;
        vowelMap['a'] = 1;
        vowelMap['e'] = 2;
        vowelMap['i'] = 4;
        vowelMap['o'] = 8;
        vowelMap['u'] = 16;

        vector<int> firstIdx(32, -1);
        int prefix = 0;
        int ans = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            prefix ^= vowelMap[s[i]];

            if (firstIdx[prefix] == -1 && prefix != 0) {
                firstIdx[prefix] = i;
            }

            ans = max(ans, i - firstIdx[prefix]);
        }

        return ans;
    }
};