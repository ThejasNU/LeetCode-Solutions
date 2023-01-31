class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> ageScorePair;
        for (int i = 0; i < scores.size(); i++) {
            ageScorePair.push_back({ages[i], scores[i]});
        }
        sort(ageScorePair.begin(), ageScorePair.end());
        vector<vector<int>> dp(scores.size(), vector<int>(scores.size(), -1));
        return findMaxScore(dp, ageScorePair, -1, 0);
    }
    
    int findMaxScore(vector<vector<int>>& dp, vector<pair<int, int>>& ageScorePair, int prev, int index) {
        if (index >= ageScorePair.size()) return 0;
        if (dp[prev + 1][index] != -1) return dp[prev + 1][index];

        // If we can add this player, return the maximum of two choices we have.
        if (prev == -1 || ageScorePair[index].second >= ageScorePair[prev].second) return dp[prev + 1][index] = max(findMaxScore(dp, ageScorePair, prev, index + 1),ageScorePair[index].second + findMaxScore(dp, ageScorePair, index, index + 1));
        
        // This player cannot be added; return the corresponding score.
        return dp[prev + 1][index] = findMaxScore(dp, ageScorePair, prev, index + 1);
    }
};