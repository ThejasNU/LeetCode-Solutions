class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);
        bitset<51> seen;
        int count = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (seen[A[i]]) {
                ++count;
            } else {
                seen.set(A[i]);
            }

            if (seen[B[i]]) {
                ++count;
            } else {
                seen.set(B[i]);
            }

            ans[i] = count;
        }
        return ans;
    }
};