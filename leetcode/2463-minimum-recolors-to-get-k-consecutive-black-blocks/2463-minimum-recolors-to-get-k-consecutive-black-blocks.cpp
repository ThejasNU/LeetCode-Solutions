class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int w = 0, b = 0;
        int ans = INT_MAX;

        int i = 0;
        for (; i < k; ++i) {
            if (blocks[i] == 'W') {
                ++w;
            } else {
                ++b;
            }
        }
        ans = min(ans, w);

        for (; i < blocks.size(); ++i) {
            if (blocks[i - k] == 'W') {
                --w;
            } else {
                --b;
            }

            if (blocks[i] == 'W') {
                ++w;
            } else {
                ++b;
            }

            ans = min(ans, w);
        }

        return ans;
    }
};