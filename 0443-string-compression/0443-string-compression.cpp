class Solution{
public:
    int compress(vector<char>& chars){
        int n=chars.size();
        int i=0,res=0;
        while(i<n){
            int count=1;
            while(i+count<n && chars[i+count]==chars[i]) count++;
            
            chars[res]=chars[i];
            ++res;
            
            if(count>1){
                string s=to_string(count);
                for(char c:s){
                    chars[res]=c;
                    ++res;
                }
            }
            i+=count;
        }
        return res;
    }
};


class noobSolution {
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