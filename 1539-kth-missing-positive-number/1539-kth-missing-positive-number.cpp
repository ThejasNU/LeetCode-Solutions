class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int k1=k;
        int dif=arr[0]-1;
        k-=dif;
        
        int i=0;
        while(i<n-1 && k>0){
            dif=arr[i+1]-arr[i]-1;
            if(k<=dif) return arr[i]+k;
            k-=dif;
            ++i;
        }
        
        if(k>0) return arr[n-1]+k;
        
        return k1;
    }
};