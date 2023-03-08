class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        while(l<r){
            int mid=(l+r)/2;
            if(possible(piles,h,mid)) r=mid;
            else l=mid+1;
        }
        return r;
    }
    
    bool possible(vector<int>& piles, int h,int k){
        int count=0;
        for(int n:piles){
            count+=n/k;
            if(n%k!=0) ++count;
        }
        return count<=h;
    }
};