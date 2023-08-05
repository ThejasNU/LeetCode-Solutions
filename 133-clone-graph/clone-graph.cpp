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
        if(node==NULL) return NULL;

        vector<Node*> nodes(101,NULL);
        vector<bool> visited(101,false);

        queue<Node*> q;
        q.push(node);
        nodes[node->val]=new Node(node->val);

        while(!q.empty()){
            Node* oldGraphNode=q.front();
            q.pop();
            int value=oldGraphNode->val;
            visited[value]=true;
            Node* newGraphNode=nodes[value];

            for(Node* nextNode:oldGraphNode->neighbors){
                if(visited[nextNode->val]) continue;

                Node* newNextNode;
                if(nodes[nextNode->val]==NULL){
                    newNextNode=new Node(nextNode->val);
                    nodes[nextNode->val]=newNextNode;
                }
                else{
                    newNextNode=nodes[nextNode->val];
                }
                newGraphNode->neighbors.push_back(newNextNode);
                newNextNode->neighbors.push_back(newGraphNode);
                q.push(nextNode);
            }
        }
        return nodes[node->val];
    }
};