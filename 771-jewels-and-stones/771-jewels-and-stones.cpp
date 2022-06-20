class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> jew;
        
        for(int i=0;i<jewels.size();++i){
            jew[jewels[i]]=1;
        }
        
        int count=0;
        
        for(int j=0;j<stones.size();++j){
            if(jew.find(stones[j])!=jew.end()) count++;
        }
        
        return count;
    }
};