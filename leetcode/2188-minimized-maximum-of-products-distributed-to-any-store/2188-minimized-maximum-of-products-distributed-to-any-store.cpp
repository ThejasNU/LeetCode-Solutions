class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 0;
        int r = *max_element(quantities.begin(), quantities.end());

        while (l < r) {
            int mid = (l + r) / 2;

            if (canDistribute(mid, n, quantities)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }

private:
    bool canDistribute(int x, int n, vector<int>& quantities) {
        int j = 0;
        int cur = quantities[0];

        for (int i = 0; i < n; ++i) {
            if (cur <= x) {
                ++j;
                if (j == quantities.size()) {
                    return true;
                } else {
                    cur = quantities[j];
                }
            } else {
                cur -= x;
            }
        }

        return false;
    }
};