class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxEle = 0, ans = 0;
        for (int i = 0; i < arr.size(); ++i) {
            maxEle = max(maxEle, arr[i]);
            if (maxEle == i) {
                ++ans;
            }
        }
        return ans;
    }
};