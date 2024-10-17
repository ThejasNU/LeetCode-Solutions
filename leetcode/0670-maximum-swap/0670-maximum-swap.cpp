class Solution {
public:
    int maximumSwap(int num) {
        string n = to_string(num);
        int maxi = -1, idx1 = -1, idx2 = -1;

        for (int i = n.size() - 1; i >= 0; --i) {
            if (maxi == -1 || n[i] > n[maxi]) {
                maxi = i;
            } else if (n[i] < n[maxi]) {
                idx1 = i;
                idx2 = maxi;
            }
        }

        if (idx1 != -1 && idx2 != -1) {
            swap(n[idx1], n[idx2]);
        }

        return stoi(n);
    }
};