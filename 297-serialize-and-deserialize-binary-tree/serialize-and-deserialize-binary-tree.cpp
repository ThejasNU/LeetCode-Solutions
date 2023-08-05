/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string ans="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            if(cur==NULL){
                ans.append("N,");
                continue;
            }
            ans.append(to_string(cur->val)+",");
            q.push(cur->left);
            q.push(cur->right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;
        
        stringstream str(data);
        string curNum;
        
        queue<TreeNode*> q;
        
        getline(str,curNum,',');
        TreeNode* root=new TreeNode(stoi(curNum));
        q.push(root);

        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();

            TreeNode* leftNode=NULL;
            getline(str,curNum,',');
            if(curNum!="N") leftNode=new TreeNode(stoi(curNum));
            if(leftNode!=NULL) q.push(leftNode);
            
            TreeNode* rightNode=NULL;
            getline(str,curNum,',');
            if(curNum!="N") rightNode=new TreeNode(stoi(curNum));
            if(rightNode!=NULL) q.push(rightNode);

            cur->left=leftNode;
            cur->right=rightNode;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));