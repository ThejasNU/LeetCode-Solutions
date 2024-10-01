class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for (int num : arr) {
            m[(num % k + k) % k] += 1;
        }
        for (int num : arr) {
            int rem = (num % k + k) % k;
            if (rem == 0) {
                if (m[rem] % 2 == 1) {
                    return false;
                }
            } else if (m[rem] != m[k - rem]) {
                return false;
            }
        }
        return true;
    }
};