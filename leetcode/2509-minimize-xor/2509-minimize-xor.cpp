class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int targetCnt = __builtin_popcount(num2);
        int setCnt = __builtin_popcount(num1);

        int ans = num1;

        if (setCnt < targetCnt) {
            for (int i = 0; i < 32 && setCnt < targetCnt; ++i) {
                if (!isSet(ans, i)) {
                    setBit(ans, i);
                    ++setCnt;
                }
            }
        } else {
            for (int i = 0; i < 32 && setCnt > targetCnt; ++i) {
                if (isSet(ans, i)) {
                    unsetBit(ans, i);
                    --setCnt;
                }
            }
        }

        return ans;
    }

private:
    bool isSet(int x, int bit) { return (x >> bit) & 1; }

    void setBit(int& x, int bit) { x |= (1 << bit); }

    void unsetBit(int& x, int bit) { x &= ~(1 << bit); }
};