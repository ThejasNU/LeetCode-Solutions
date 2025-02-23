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
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        return helper(0, preorder.size() - 1, 0, preorder, postorder);
    }

private:
    TreeNode* helper(int preS, int preE, int postS, vector<int>& preorder,
                     vector<int>& postorder) {
        if (preS > preE) {
            return nullptr;
        }

        if (preS == preE) {
            return new TreeNode(preorder[preS]);
        }

        TreeNode* node = new TreeNode(preorder[preS]);

        int leftVal = preorder[preS + 1];
        int numLeftNodes = 0;
        while (postorder[postS + numLeftNodes] != leftVal) {
            ++numLeftNodes;
        }
        ++numLeftNodes;

        node->left =
            helper(preS + 1, preS + numLeftNodes, postS, preorder, postorder);
        node->right = helper(preS + numLeftNodes + 1, preE,
                             postS + numLeftNodes, preorder, postorder);

        return node;
    }
};