class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> count2(26, 0);
        for (string& w2 : words2) {
            vector<int> temp(26, 0);
            for (char c : w2) {
                temp[c - 'a'] += 1;
                count2[c - 'a'] = max(count2[c - 'a'], temp[c - 'a']);
            }
        }

        vector<string> ans;
        for (string& w1 : words1) {
            vector<int> count1(26, 0);
            for (char c : w1) {
                count1[c - 'a'] += 1;
            }

            bool isSubset = true;
            for (int i = 0; i < 26; ++i) {
                if (count1[i] < count2[i]) {
                    isSubset = false;
                    break;
                }
            }

            if (isSubset) {
                ans.push_back(w1);
            }
        }

        return ans;
    }
};