class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]==word[0]){
                    if(helper(0,i,j,board,word)) return true;
                } 
            }
        }
        
        return false;
    }
    
    bool helper(int index,int i,int j,vector<vector<char>>& board, string &word){
        int m=board.size();
        int n=board[0].size();
        board[i][j]='@';
        if(index==word.size()-1) return true;
        
        if(i<m-1 && board[i+1][j]==word[index+1]) if(helper(index+1,i+1,j,board,word)) return true;
        if(i>0 && board[i-1][j]==word[index+1]) if(helper(index+1,i-1,j,board,word)) return true;
        if(j<n-1 && board[i][j+1]==word[index+1]) if(helper(index+1,i,j+1,board,word)) return true;
        if(j>0 && board[i][j-1]==word[index+1]) if(helper(index+1,i,j-1,board,word)) return true;
        
        board[i][j]=word[index];
        return false;
    }
};