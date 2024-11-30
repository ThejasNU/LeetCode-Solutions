class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, queue<int>> adjacencyMatrix;
        unordered_map<int, int> inDegree, outDegree;

        for (const auto& pair : pairs) {
            int start = pair[0], end = pair[1];
            adjacencyMatrix[start].push(end);
            outDegree[start]++;
            inDegree[end]++;
        }

        vector<int> result;

        int startNode = -1;
        for (const auto& entry : outDegree) {
            int node = entry.first;
            if (outDegree[node] == inDegree[node] + 1) {
                startNode = node;
                break;
            }
        }

        if (startNode == -1) {
            startNode = pairs[0][0];
        }

        stack<int> nodeStack;
        nodeStack.push(startNode);

        while (!nodeStack.empty()) {
            int node = nodeStack.top();
            if (!adjacencyMatrix[node].empty()) {
                int nextNode = adjacencyMatrix[node].front();
                adjacencyMatrix[node].pop();
                nodeStack.push(nextNode);
            } else {
                result.push_back(node);
                nodeStack.pop();
            }
        }

        reverse(result.begin(), result.end());

        vector<vector<int>> pairedResult;
        for (int i = 1; i < result.size(); ++i) {
            pairedResult.push_back({result[i - 1], result[i]});
        }

        return pairedResult;
    }
};