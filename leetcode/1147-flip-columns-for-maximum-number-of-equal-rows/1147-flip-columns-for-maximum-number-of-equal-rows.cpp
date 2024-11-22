class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> m;
        for (auto& row : matrix) {
            string cur = "";
            for (int col = 0; col < row.size(); ++col) {
                if (row[0] == row[col]) {
                    cur.push_back('T');
                } else {
                    cur.push_back('F');
                }
            }
            m[cur] += 1;
        }
        int ans = 0;
        for (auto& [pattern, freq] : m) {
            ans = max(ans, freq);
        }
        return ans;
    }
};