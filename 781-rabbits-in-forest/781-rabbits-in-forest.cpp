class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map <int,int> extraCount;
        for(int i=0;i<answers.size();++i){
            if(extraCount[answers[i]]==0){
                extraCount[answers[i]]=answers[i];
            }
            else{
                extraCount[answers[i]]--;
            }
        }
        int sol=0;
        for(auto ele:extraCount){
            sol+=ele.second;
        }
        sol+=answers.size();
        
        return sol;
        
    }
};