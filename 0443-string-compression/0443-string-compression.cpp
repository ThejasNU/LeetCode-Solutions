class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        auto it=chars.begin()+1;
        while(it!=chars.end()){
            int count=1;
            while(it!=chars.end() && *it==*(it-1)){
                chars.erase(it);
                ++count;
            }
            
            if(count>1){
                string s=to_string(count);
                for(char c:s){
                    chars.insert(it,c);
                    it++;
                }
            }
            
            if(it!=chars.end()) it++;
        }
        
        return chars.size();
    }
    
};