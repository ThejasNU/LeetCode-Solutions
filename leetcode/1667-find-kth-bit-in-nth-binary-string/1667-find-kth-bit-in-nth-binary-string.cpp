class Solution {
public:
    char findKthBit(int n, int k) {
        vector<string> binaryStrings(n);
        binaryStrings[0] = "0";
        for (int i = 1; i < n; ++i) {
            binaryStrings[i] = binaryStrings[i - 1] + "1" +
                               invertAndReverse(binaryStrings[i - 1]);
        }

        return binaryStrings[n - 1][k - 1];
    }

    string invertAndReverse(string s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') {
                s[i] = '1';
            } else {
                s[i] = '0';
            }
        }

        reverse(s.begin(), s.end());

        return s;
    }
};