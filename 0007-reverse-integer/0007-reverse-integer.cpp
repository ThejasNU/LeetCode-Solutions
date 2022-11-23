class Solution {
public:
    int reverse(int x) {
        bool neg=(x<0?true:false);
        long long y=x;
        if(neg) y*=-1;
        string str=to_string(y);
        std::reverse(str.begin(),str.end());
        long long temp=stoll(str);
        if((!neg&&temp>INT_MAX) || (neg&& temp*-1<INT_MIN)) return 0;
        else return (neg?(int)temp*-1:(int)temp);

    }
};