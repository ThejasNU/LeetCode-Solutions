class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1,r=1e7;
        int ans=-1;
        while(l<=r){
            int speed=(l+r)/2;
            if(canTravel(dist,speed,hour)){
                ans=speed;
                r=speed-1;
            }
            else{
                l=speed+1;
            }
        }
        return ans;
    }

    bool canTravel(vector<int>& dist,int speed,double hour){
        double time=0.0;
        for(int i=0;i<dist.size();++i){
            double t = (double) dist[i] / (double) speed;
            time += (i == dist.size() - 1 ? t : ceil(t));
        }
        return time<=hour;
    }
};