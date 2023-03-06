class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        unordered_map<int,unordered_set<int>> row,col;
        
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                row[i].insert(matrix[i][j]);
                col[j].insert(matrix[i][j]);
            }
        }
        
        for(auto it:row){
            if(it.second.size()!=n) return false;
        }
        
        for(auto it:col){
            if(it.second.size()!=n) return false;
        }
        return true;
    }
};