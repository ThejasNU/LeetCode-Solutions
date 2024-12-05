class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();

        int i = 0, j = 0;
        while (i < n || j < n) {
            while (i < n && start[i] == '_') {
                ++i;
            }
            while (j < n && target[j] == '_') {
                ++j;
            }

            if (i == n || j == n) {
                return i == n && j == n;
            }

            if (start[i] != target[j] || (start[i] == 'L' && i < j) ||
                (start[i] == 'R' && i > j)) {
                return false;
            }

            ++i;
            ++j;
        }

        return true;
    }
};