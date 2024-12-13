class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (int i = 0; i < nums.size(); ++i) {
            pq.push({nums[i], i});
        }

        vector<bool> marked(nums.size(), false);
        long long ans = 0;
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int num = cur.first;
            int idx = cur.second;

            if (!marked[idx]) {
                ans += num;
                marked[idx] = true;

                if (idx - 1 >= 0 && !marked[idx - 1]) {
                    marked[idx - 1] = true;
                }

                if (idx + 1 < nums.size() && !marked[idx + 1]) {
                    marked[idx + 1] = true;
                }
            }
        }

        return ans;
    }
};