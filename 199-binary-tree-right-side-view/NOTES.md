Iterative solution
```cpp
class Solution {
public:
vector<int> rightSideView(TreeNode* root) {
vector<int> res;
if(root==NULL) return res;
queue<TreeNode*> q;
q.push(root);
while(!q.empty()){
int len=q.size();
for(int i=0;i<len-1;++i){
TreeNode* temp=q.front();
q.pop();
if(temp->left) q.push(temp->left);
if(temp->right) q.push(temp->right);
}
TreeNode *temp=q.front();
q.pop();
if(temp->left) q.push(temp->left);
if(temp->right) q.push(temp->right);
res.push_back(temp->val);
}
return res;
}
};
```