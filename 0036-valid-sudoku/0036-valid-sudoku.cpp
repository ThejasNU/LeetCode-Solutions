class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,set<char>> row;
        unordered_map<int,set<char>> col;
        unordered_map<int,set<char>> box;

        int boxNum;

        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]!='.'){
                    boxNum=((i/3)*3)+(j/3);
                    if(row[i].find(board[i][j])==row[i].end() && col[j].find(board[i][j])==col[j].end() && box[boxNum].find(board[i][j])==box[boxNum].end()){
                        row[i].insert(board[i][j]);
                        col[j].insert(board[i][j]);
                        box[boxNum].insert(board[i][j]);
                    } 
                    else return false;
                }
            }
        }

        return true;
    }
};