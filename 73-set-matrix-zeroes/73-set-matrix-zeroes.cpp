class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0=1; //this is used to tell whether we have zero in 0th column or not, 1 means no there, 0 means 0 is there
        int rows= matrix.size();
        int cols=matrix[0].size();
        
        for(int i=0;i<rows;++i){
            if(matrix[i][0]==0) col0=0;
            
            for(int j=1;j<cols;++j){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        //now go from last element to the first element, this is will avoid keeping extra row0 similar to col0
        for(int i=rows-1;i>=0;--i){
            for(int j=cols-1;j>=1;--j){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
            if(!col0) matrix[i][0]=0;
        }
        
    }
};