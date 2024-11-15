class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int r = arr.size() - 1;
        while (r > 0 && arr[r] >= arr[r - 1]) {
            --r;
        }
        int l = 0, ans = r;
        while (l < r && (l == 0 || arr[l] >= arr[l - 1])) {
            while (r < arr.size() && arr[l] > arr[r]) {
                ++r;
            }
            ans = min(ans, r - l - 1);
            ++l;
        }
        return ans;
    }
};