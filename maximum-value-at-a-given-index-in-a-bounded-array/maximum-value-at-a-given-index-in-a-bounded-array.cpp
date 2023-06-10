class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long long l=1,r=maxSum;
        while(l<r){
            long long m=(l+r+1)/2;
            if(getSum(index,m,n)<=maxSum){
                l=m;
            }
            else{
                r=m-1;
            }
        }
        return l;
    }

    long long getSum(long long index,long long value,long long n){
        long long count=0;
        
        if(value>index) count+=(value+value-index)*(index+1)/2;
        else count+=(value+1)*value/2 + index-value+1;

        if(value>=n-index) count+=(value+value-n+1+index)*(n-index)/2;
        else count+=(value+1)*value/2 + n-index-value;

        return count-value;
    }
};