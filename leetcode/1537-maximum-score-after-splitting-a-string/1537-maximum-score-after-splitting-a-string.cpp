class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> numOnes(n, 0);

        int onesCount = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1') {
                onesCount++;
            }
            numOnes[i] = onesCount;
        }

        int zerosCount = 0;
        int maxScore = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '0') {
                zerosCount++;
            }
            maxScore = max(maxScore, zerosCount + numOnes[i + 1]);
        }
        return maxScore;
    }
};