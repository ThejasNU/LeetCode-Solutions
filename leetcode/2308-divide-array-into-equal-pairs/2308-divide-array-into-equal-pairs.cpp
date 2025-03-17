class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> st;
        for (int num : nums) {
            if (st.find(num) != st.end()) {
                st.erase(num);
            } else {
                st.insert(num);
            }
        }
        return st.empty();
    }
};