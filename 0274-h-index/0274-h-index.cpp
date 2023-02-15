class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = 0;
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 1; i <= citations.size(); i++) {
            if (citations[i-1] < i) break;
            ans = i;
        }
        return ans;
    }
};