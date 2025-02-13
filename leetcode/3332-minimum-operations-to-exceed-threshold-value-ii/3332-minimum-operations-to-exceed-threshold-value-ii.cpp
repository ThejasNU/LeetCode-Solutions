class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (long long num : nums) {
            pq.push(num);
        }
        int ops = 0;
        while (pq.size() >= 2) {
            long long cur = pq.top();
            pq.pop();
            if (cur >= k) {
                return ops;
            }
            long long next = pq.top();
            pq.pop();
            pq.push(min(cur, next) * 2 + max(cur, next));
            ++ops;
        }
        return ops;
    }
};