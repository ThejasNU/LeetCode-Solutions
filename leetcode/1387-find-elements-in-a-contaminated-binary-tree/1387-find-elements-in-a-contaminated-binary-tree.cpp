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
class FindElements {
public:
    FindElements(TreeNode* root) { this->root = root; }

    bool find(int target) {
        if (target == 0) {
            return this->root != nullptr;
        }

        int path = target + 1;
        int level = log2(path);

        TreeNode* node = root;
        int mask = 1 << (level - 1);
        while (mask > 0 && node != nullptr) {
            if ((path & mask) == 0) {
                node = node->left;
            } else {
                node = node->right;
            }

            mask >>= 1;
        }

        return node != nullptr;
    }

private:
    TreeNode* root;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */