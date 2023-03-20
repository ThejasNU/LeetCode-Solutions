class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i=0;i<flowerbed.size();++i){
            if(flowerbed[i]==1){
                //skip 2 places coz we can't plant in adjacent plots
                ++i;
                continue;
            }
            
            bool emptyLeftPlot=(i==0)||(flowerbed[i-1]==0);
            bool emptyRightPlot=(i==flowerbed.size()-1)||(flowerbed[i+1]==0);
            if(emptyLeftPlot && emptyRightPlot){
                flowerbed[i]=1;
                --n;
                if(n<=0) return true;
                //skip 2 places coz we can't plant in adjacent plots
                ++i;
            }
        }
        return n<=0;
    }
};