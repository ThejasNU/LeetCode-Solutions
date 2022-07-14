If both row and col are sorted
​
```
class Solution {
public:
bool searchMatrix(vector<vector<int>>& matrix, int target) {
int m=matrix[0].size(),n=matrix.size();
int i=0,j=m-1;
while(i<n && j>=0){
if(matrix[i][j]==target){
return true;
}
if(matrix[i][j]>target){
j--;
}
else{
i++;
}
}
return false;
}
};
```