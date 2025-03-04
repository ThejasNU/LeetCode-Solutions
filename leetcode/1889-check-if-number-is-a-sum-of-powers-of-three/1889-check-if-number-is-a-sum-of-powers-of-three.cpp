class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            // same power has to be used twice
            if (n % 3 == 2) {
                return false;
            }

            n /= 3;
        }
        return true;
    }
};