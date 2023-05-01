class Solution {
public:
    double average(vector<int>& salary) {
        int mini=INT_MAX,maxi=INT_MIN,sum=0;

        for(int x:salary){
            sum+=x;
            mini=min(mini,x);
            maxi=max(maxi,x);
        }

        return (double)(sum-mini-maxi)/(double)(salary.size()-2);
    }
};