class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        int extra = 0;
        for (char c : s) {
            if (c == '(') {
                ++count;
            } else {
                if (count > 0) {
                    --count;
                } else {
                    ++extra;
                }
            }
        }
        return count + extra;
    }
};