/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        queue<TreeNode*> q;
        parent[root]=NULL;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            if(cur->left){
                parent[cur->left]=cur;
                q.push(cur->left);
            }
            if(cur->right){
                parent[cur->right]=cur;
                q.push(cur->right);
            }
        }

        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        int level=0;
        while(!q.empty()){
            if(level==k) break;
            int size=q.size();
            while(size--){
                TreeNode* cur=q.front();
                q.pop();
                if(cur->left && visited.find(cur->left)==visited.end()){
                    q.push(cur->left);
                    visited.insert(cur->left);
                }
                if(cur->right && visited.find(cur->right)==visited.end()){
                    q.push(cur->right);
                    visited.insert(cur->right);
                }
                if(parent[cur] && visited.find(parent[cur])==visited.end()){
                    q.push(parent[cur]);
                    visited.insert(parent[cur]);
                }
            }
            level+=1;
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};














