class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        vector<vector<bool>> isPrereq(numCourses,
                                      vector<bool>(numCourses, false));

        for (auto prereq : prerequisites) {
            isPrereq[prereq[0]][prereq[1]] = true;
        }

        for (int mid = 0; mid < numCourses; ++mid) {
            for (int src = 0; src < numCourses; ++src) {
                for (int dest = 0; dest < numCourses; ++dest) {
                    isPrereq[src][dest] =
                        isPrereq[src][dest] ||
                        (isPrereq[src][mid] && isPrereq[mid][dest]);
                }
            }
        }

        vector<bool> ans;
        for (auto query : queries) {
            ans.push_back(isPrereq[query[0]][query[1]]);
        }

        return ans;
    }
};