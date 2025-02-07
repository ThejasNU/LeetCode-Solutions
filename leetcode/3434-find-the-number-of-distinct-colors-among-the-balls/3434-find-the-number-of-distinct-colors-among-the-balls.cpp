class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballClr, clrCnt;

        vector<int> ans;
        for (vector<int>& query : queries) {
            int ball = query[0];
            int clr = query[1];

            if (ballClr.find(ball) != ballClr.end()) {
                int prevClr = ballClr[ball];
                clrCnt[prevClr]--;
                if (clrCnt[prevClr] == 0) {
                    clrCnt.erase(prevClr);
                }
            }

            ballClr[ball] = clr;
            clrCnt[clr]++;

            ans.push_back(clrCnt.size());
        }

        return ans;
    }
};