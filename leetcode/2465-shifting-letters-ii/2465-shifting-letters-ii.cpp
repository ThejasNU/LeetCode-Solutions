class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> dif(s.size(), 0);
        for (auto shift : shifts) {
            if (shift[2] == 0) {
                dif[shift[0]]--;
                if (shift[1] + 1 < s.size()) {
                    dif[shift[1] + 1]++;
                }
            } else {
                dif[shift[0]]++;
                if (shift[1] + 1 < s.size()) {
                    dif[shift[1] + 1]--;
                }
            }
        }

        string ans(s.size(), ' ');
        int numShift = 0;
        for (int i = 0; i < s.size(); ++i) {
            numShift = (numShift + dif[i]) % 26;
            if(numShift<0){
                numShift+=26;
            }
            ans[i] = 'a' + (s[i] - 'a' + numShift) % 26;
        }

        return ans;
    }
};