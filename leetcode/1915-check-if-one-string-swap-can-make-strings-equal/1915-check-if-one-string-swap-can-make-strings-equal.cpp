class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }

        int count = 0, firstDif = 0, secondDif = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                ++count;

                if (count > 2) {
                    return false;
                } else if (count == 1) {
                    firstDif = i;
                } else {
                    secondDif = i;
                }
            }
        }

        return s1[firstDif] == s2[secondDif] && s1[secondDif] == s2[firstDif];
    }
};