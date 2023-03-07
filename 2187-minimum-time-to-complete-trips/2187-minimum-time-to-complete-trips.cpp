class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=*min_element(time.begin(),time.end());
        long long r=*max_element(time.begin(),time.end())*1LL*totalTrips;
        
        while(l<r){
            long long mid=(l+r)/2;
            long long trips=computeTotalTrips(time,mid);
            if(trips<totalTrips) l=mid+1;
            //because we might find a time lesser than the mid
            else r=mid;
        }
        return l;
    }
    
    long long computeTotalTrips(vector<int>& time,long long mid){
        long long total=0;
        for(int n:time){
            total+=mid/n;
        }
        return total;
    }
};