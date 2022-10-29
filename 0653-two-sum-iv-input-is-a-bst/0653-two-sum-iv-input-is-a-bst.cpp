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
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL || (!root->left && !root->right)) return false;
        
        stack<TreeNode*> nextSt;
        stack<TreeNode*> beforeSt;
        pushNext(nextSt,root);
        pushBefore(beforeSt,root);
        
        TreeNode* low=findNext(nextSt);
        TreeNode* high=findBefore(beforeSt);
        
        while(low!=high && !nextSt.empty() && !beforeSt.empty()){
            if(low->val+high->val>k) high=findBefore(beforeSt);
            else if(low->val+high->val<k) low=findNext(nextSt);
            else return true;
        }
        
        return false;
    }
    
    TreeNode* findNext(stack<TreeNode*> &s){
        TreeNode* temp=s.top();
        s.pop();
        pushNext(s,temp->right);
        return temp;
    }
    
    TreeNode* findBefore(stack<TreeNode*> &s){
        TreeNode* temp=s.top();
        s.pop();
        pushBefore(s,temp->left);
        return temp;
    }
    
    void pushNext(stack<TreeNode*> &s,TreeNode* node){
        while(node!=NULL){
            s.push(node);
            node=node->left;
        }
    }
    
    void pushBefore(stack<TreeNode*> &s,TreeNode* node){
        while(node!=NULL){
            s.push(node);
            node=node->right;
        }
    }
};