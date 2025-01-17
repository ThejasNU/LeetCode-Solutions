class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int XOR = 0;
        for (int num : derived) {
            XOR ^= num;
        }
        return XOR == 0;
    }
};