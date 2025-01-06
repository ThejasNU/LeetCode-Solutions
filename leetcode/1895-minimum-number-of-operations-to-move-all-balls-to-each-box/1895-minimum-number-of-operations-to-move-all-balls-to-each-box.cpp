class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        vector<int> ans(n, 0);
        int leftBalls = 0, leftMoves = 0, rightBalls = 0, rightMoves = 0;
        for (int i = 0; i < n; ++i) {
            ans[i] += leftMoves;
            leftBalls += boxes[i] - '0';
            leftMoves += leftBalls;

            int j = n - 1 - i;
            ans[j] += rightMoves;
            rightBalls += boxes[j] - '0';
            rightMoves += rightBalls;
        }

        return ans;
    }
};