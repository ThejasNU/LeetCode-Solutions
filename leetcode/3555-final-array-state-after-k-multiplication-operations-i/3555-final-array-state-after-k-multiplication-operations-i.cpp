class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (int i = 0; i < nums.size(); ++i) {
            pq.push({nums[i], i});
        }

        while (k--) {
            auto [num, idx] = pq.top();
            pq.pop();

            pq.push({num * multiplier, idx});
        }

        while (!pq.empty()) {
            auto [num, idx] = pq.top();
            pq.pop();

            nums[idx] = num;
        }

        return nums;
    }
};