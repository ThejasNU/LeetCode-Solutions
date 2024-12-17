class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> m;
        for (char c : s) {
            m[c] += 1;
        }

        priority_queue<char> pq;
        for (auto& [c, cnt] : m) {
            pq.push(c);
        }

        string ans = "";
        while (!pq.empty()) {
            char c = pq.top();
            pq.pop();

            int used = min(m[c], repeatLimit);
            ans.append(used, c);

            m[c] -= used;

            if (m[c] > 0 && !pq.empty()) {
                char nextC = pq.top();
                pq.pop();

                ans.push_back(nextC);
                m[nextC] -= 1;

                if (m[nextC] > 0) {
                    pq.push(nextC);
                }

                pq.push(c);
            }
        }

        return ans;
    }
};