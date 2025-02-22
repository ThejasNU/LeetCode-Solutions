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
    TreeNode* recoverFromPreorder(string traversal) {
        int idx = 0;
        return helper(traversal, idx, 0);
    }

private:
    TreeNode* helper(const string& preorder, int& idx, int level) {
        if (idx >= preorder.size()) {
            return nullptr;
        }

        int count = 0;
        while (idx + count < preorder.size() && preorder[idx + count] == '-') {
            ++count;
        }

        if (count != level) {
            return nullptr;
        }

        idx += count;

        int num = 0;
        while (idx < preorder.size() && isdigit(preorder[idx])) {
            num = num * 10 + (preorder[idx] - '0');
            ++idx;
        }

        TreeNode* node = new TreeNode(num);

        node->left = helper(preorder, idx, level + 1);
        node->right = helper(preorder, idx, level + 1);

        return node;
    }
};