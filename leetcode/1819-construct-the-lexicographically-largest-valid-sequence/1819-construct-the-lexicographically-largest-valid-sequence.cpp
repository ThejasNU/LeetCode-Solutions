class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(n * 2 - 1, -1);
        vector<bool> used(n + 1, false);
        helper(0, ans, used, n);
        return ans;
    }

private:
    bool helper(int idx, vector<int>& ans, vector<bool>& used, int n) {
        if (idx == ans.size()) {
            return true;
        }

        if (ans[idx] != -1) {
            return helper(idx + 1, ans, used, n);
        }

        for (int num = n; num >= 1; --num) {
            if (used[num]) {
                continue;
            }

            used[num] = true;
            ans[idx] = num;

            if (num == 1) {
                if (helper(idx + 1, ans, used, n)) {
                    return true;
                }
            } else if (idx + num < ans.size() && ans[idx + num] == -1) {
                ans[idx + num] = num;
                if (helper(idx + 1, ans, used, n)) {
                    return true;
                }
                ans[idx + num] = -1;
            }

            ans[idx] = -1;
            used[num] = false;
        }

        return false;
    }
};