class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int left=0, right=x;
        int res, mid;  
        while(left<=right){             
            mid=(left+right)/2;
            if(mid == 0) return 1;
            if(mid==x/mid) return mid;    
            else if(mid<x/mid){             
                left=mid+1;       
                res = mid;      
            }
            else right=mid-1;       
        }
        return res;  
    }
};