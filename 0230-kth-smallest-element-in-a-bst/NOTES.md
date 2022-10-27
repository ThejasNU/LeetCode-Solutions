iterative stack solution:
```cpp
stack<TreeNode*> st;
while(true){
while(root!=NULL){
st.push(root);
root=root->left;
}
root=st.top();
st.pop();
if(--k==0) return root->val;
root=root->right;
}
return 0;
```