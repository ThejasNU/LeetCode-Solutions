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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root==NULL) return root;
        
        queue<TreeNode*> q;
        q.push(root);
        int level=1;
        
        if(depth==1){
            TreeNode *newRoot=new TreeNode(val);
            newRoot->left=root;
            newRoot->right=NULL;
            
            return newRoot;
        }
        
        while(!q.empty()){
            int len=q.size();
            if(level+1==depth){
                while(len--){
                    TreeNode* cur=q.front();
                    q.pop();
                    TreeNode* tempL=new TreeNode(val);
                    TreeNode* tempR=new TreeNode(val);
                    TreeNode* LEFT= cur->left?cur->left:NULL;
                    TreeNode* RIGHT= cur->right?cur->right:NULL;
                    cur->left=tempL;
                    tempL->left=LEFT;
                    cur->right=tempR;
                    tempR->right=RIGHT;
                }
                break;
            }
            else{
                while(len--){
                    TreeNode* cur=q.front();
                    q.pop();
                    
                    if(cur->left) q.push(cur->left);
                    if(cur->right) q.push(cur->right);
                }
            }
            level++;
        }
        
        return root;
    }
};