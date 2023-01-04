class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> m;
        
        for(int task:tasks){
            m[task]++;
        }
        
        int rounds=0;
        for(auto [task,count]:m){
            if(count==1) return -1;
            
            if(count%3==0) rounds+=count/3;
            //if count%3==1, then instead of k groups of 3, make k-1 groups of 3 and 2 groups of 2
            //if count%3==2,then k groups of 3 and 1 group of 2
            else rounds+=count/3+1;
        }

        return rounds;
    }
};