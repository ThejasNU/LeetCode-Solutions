class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int total=n*n,num=1;
        int startingRow=0,startingCol=0,endingRow=n-1,endingCol=n-1;
        vector<vector<int>> ans(n,vector<int>(n));
        while(num<=total){
            for(int i=startingCol;num<=total && i<=endingCol;++i){
                ans[startingRow][i]=num;
                ++num;
            }
            ++startingRow;
            for(int i=startingRow;num<=total && i<=endingRow;++i){
                ans[i][endingCol]=num;
                ++num;
            }
            --endingCol;
            for(int i=endingCol;num<=total && i>=startingCol;--i){
                ans[endingRow][i]=num;
                ++num;
            }
            --endingRow;
            for(int i=endingRow;num<=total && i>=startingRow;--i){
                ans[i][startingCol]=num;
                ++num;
            }
            ++startingCol;
        }
        return ans;
    }
};