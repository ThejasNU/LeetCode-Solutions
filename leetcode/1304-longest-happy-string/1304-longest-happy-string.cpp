class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) {
            pq.push({a, 'a'});
        }
        if (b > 0) {
            pq.push({b, 'b'});
        }
        if (c > 0) {
            pq.push({c, 'c'});
        }

        string ans = "";
        while (!pq.empty()) {
            int cnt = pq.top().first;
            char character = pq.top().second;
            pq.pop();

            int len = ans.size();
            if (len >= 2 && ans[len - 1] == character &&
                ans[len - 2] == character) {
                if (pq.empty()) {
                    break;
                }

                int cnt2 = pq.top().first;
                char character2 = pq.top().second;
                pq.pop();
                
                ans.push_back(character2);
                --cnt2;

                if (cnt2 > 0) {
                    pq.push({cnt2, character2});
                }
            } else {
                ans.push_back(character);
                --cnt;
            }

            if (cnt > 0) {
                pq.push({cnt, character});
            }
        }

        return ans;
    }
};