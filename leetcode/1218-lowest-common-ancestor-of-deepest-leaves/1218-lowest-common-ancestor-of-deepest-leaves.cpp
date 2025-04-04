/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) { return helper(root).first; }

private:
    pair<TreeNode*, int> helper(TreeNode* node) {
        if (!node) {
            return {nullptr, 0};
        }

        auto left = helper(node->left);
        auto right = helper(node->right);

        if (left.second > right.second) {
            return {left.first, left.second + 1};
        } else if (right.second > left.second) {
            return {right.first, right.second + 1};
        } else {
            return {node, right.second + 1};
        }
    }
};