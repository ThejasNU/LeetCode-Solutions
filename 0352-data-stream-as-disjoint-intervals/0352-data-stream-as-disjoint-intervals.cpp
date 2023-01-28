class SummaryRanges {
private:
    set<int> nums;
public:
    
    SummaryRanges() {}
    
    void addNum(int value) {
        nums.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> intervals;
        int left=-1,right=-1;
        if(nums.size()>0){
            for(int num:nums){
                if(left<0){
                    left=right=num;
                }
                else if(num==right+1){
                    right=num;
                }
                else{
                    intervals.push_back({left,right});
                    left=right=num;
                }
            }
            intervals.push_back({left,right});
        }
        return intervals;
    }
};

class mergeIntervalsSolution {
private:
    vector<vector<int>> intervals;
public:
    void addNum(int value) {
       intervals.push_back({value,value});
    }
    
    vector<vector<int>> getIntervals() {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> solved;
        int n=intervals.size();
        if(n>0){
            vector<int> temp=intervals[0];
            for(int i=1;i<n;++i){
                if(intervals[i][0]-temp[1]<2){
                    temp[1]=max(intervals[i][1],temp[1]);
                }
                else{
                    solved.push_back(temp);
                    temp=intervals[i];
                }
            }
            solved.push_back(temp);
        }
        intervals=solved;
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */