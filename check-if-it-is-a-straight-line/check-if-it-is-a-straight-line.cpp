class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int deltaX=coordinates[0][0]-coordinates[1][0];
        int deltaY=coordinates[0][1]-coordinates[1][1];
        int n=coordinates.size();
        double x1,x2,y1,y2;
        for(int i=2;i<n;++i){
            y2=coordinates[i][1];
            y1=coordinates[0][1];
            x2=coordinates[i][0];
            x1=coordinates[0][0];
            if((y1-y2)*deltaX!=(x1-x2)*deltaY) return false;
        }
        return true;
    }
};