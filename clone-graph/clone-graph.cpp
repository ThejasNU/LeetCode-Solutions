/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        vector<Node*> nodes(101, nullptr);
        vector<bool> visited(101, false);
        queue<Node*> q;

        q.push(node);
        Node* copyCur = new Node(node->val, {});
        nodes[node->val] = copyCur;

        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            copyCur = nodes[cur->val];
            visited[cur->val] = true;
            for (Node* neigh : cur->neighbors) {
                if (visited[neigh->val]) continue;

                Node* copyNode = nodes[neigh->val] == nullptr ? new Node(neigh->val, {}) : nodes[neigh->val];
                nodes[neigh->val] = copyNode;
                copyNode->neighbors.push_back(copyCur);
                copyCur->neighbors.push_back(copyNode);
                q.push(neigh);
            }
        }
        return nodes[node->val];
    }
};