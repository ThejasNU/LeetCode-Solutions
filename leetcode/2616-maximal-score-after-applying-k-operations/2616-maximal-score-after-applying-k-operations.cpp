class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq;
        for (long long num : nums) {
            pq.push(num);
        }

        long long ans = 0;
        while (k--) {
            long long maxx = pq.top();
            pq.pop();
            ans += maxx;
            pq.push(findCeil(maxx));
        }

        return ans;
    }

    long long findCeil(long long num) {
        return num % 3 == 0 ? num / 3 : (num / 3) + 1;
    }
};