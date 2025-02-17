class Solution {
public:
    int numTilePossibilities(string tiles) {
        array<int, 26> count;
        count.fill(0);
        for (char c : tiles) {
            ++count[c - 'A'];
        }
        return helper(count);
    }

private:
    int helper(array<int, 26>& count) {
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i] == 0) {
                continue;
            }
            ++res;
            --count[i];
            res += helper(count);
            ++count[i];
        }
        return res;
    }
};