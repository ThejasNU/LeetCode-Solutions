class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int l=0,r=((m-1)*n)+n-1;
        cout<<r<<endl;
        while(l<=r){
            int mid=(l+r)/2;
            int i=mid/n;
            int j=mid%n;
            cout<<mid<<" "<<i<<" "<<j<<endl;
            if(matrix[i][j]<target) l=mid+1;
            else if(matrix[i][j]>target) r=mid-1;
            else return true;
        }
        return false;
    }
};