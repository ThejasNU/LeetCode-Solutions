/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    //Iteative inorder traversal
public:
    BSTIterator(TreeNode* root) {
        pushNodes(root);    
    }
    
    int next() {
        TreeNode* temp=st.top();
        st.pop();
        pushNodes(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
private:
    stack<TreeNode*>st;
    
    void pushNodes(TreeNode* node){
        while(node!=NULL){
            st.push(node);
            node=node->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */