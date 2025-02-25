class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int M = 1e9 + 7;
        int ans = 0, prefix = 0, odd = 0, even = 1;
        for (int num : arr) {
            prefix += num;
            if (prefix & 1) {
                ans += even;
                ++odd;
            } else {
                ans += odd;
                ++even;
            }
            ans %= M;
        }
        return ans;
    }
};