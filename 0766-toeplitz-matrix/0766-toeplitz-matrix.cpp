class Solution {
public:
    //compare all elements of the diagonal with the first element
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return true;
        
        for(int i=1;i<matrix.size();++i){
            for(int j=1;j<matrix[0].size();++j){
                if(matrix[i-1][j-1]!=matrix[i][j]) return false;
            }
        }
        
        return true;
    }
};