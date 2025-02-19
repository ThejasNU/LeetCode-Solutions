class Solution {
public:
    string getHappyString(int n, int k) {
        string ans = "";

        for (char i = 'a'; i <= 'c'; ++i) {
            string cur = "";
            cur.push_back(i);
            generate(n, k, cur, ans);
            if (ans != "") {
                return ans;
            }
        }

        return "";
    }

private:
    void generate(int n, int& k, string& cur, string& ans) {
        if (cur.size() == n) {
            --k;
            if (k == 0) {
                ans = cur;
            }
            return;
        }

        for (char i = 'a'; i <= 'c'; ++i) {
            if (cur.back() == i) {
                continue;
            }

            cur.push_back(i);
            generate(n, k, cur, ans);
            if (ans != "") {
                return;
            }
            cur.pop_back();
        }
    }
};