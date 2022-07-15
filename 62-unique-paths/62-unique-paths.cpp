class Solution {
public:
    
    //combinatronics solution
    int uniquePaths(int m, int n) {
        
        //number of turn needed to be taken to reach, it will be fixed for a problem, observe the pattern
        int N= m+n-2;
        
        int r=m-1;
        
        double res=1;
        
        for(int i=1;i<=r;++i){
            res=res*(N-r+i)/i;
        }
        
        return (int)res;
    }
};