class Solution {
public:
    int bestClosingTime(string customers) {
        int curPen=0,minPen=0,earliestHour=0;

        for(int i=0;i<customers.size();++i){
            if(customers[i]=='Y'){
                curPen-=1;
            }
            else{
                curPen+=1;
            }

            if(curPen<minPen){
                earliestHour=i+1;
                minPen=curPen;
            }
        }

        return earliestHour;
    }
};