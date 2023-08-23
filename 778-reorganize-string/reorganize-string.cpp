class Solution {
public:
    string reorganizeString(string s) {
        vector<int> counter(26,0);
        for(char c:s){
            counter[c-'a']+=1;
        }

        auto it=max_element(counter.begin(),counter.end());
        int maxCount=*it;
        int letter=it-counter.begin();

        if(maxCount>(s.size()+1)/2) return "";

        string ans=s;
        int idx=0;
        char c='a'+letter;
        while(counter[letter]!=0){
            ans[idx]=c;
            idx+=2;
            counter[letter]-=1;
        }

        for(int i=0;i<counter.size();++i){
            c='a'+i;
            while(counter[i]!=0){
                if(idx>=s.size()){
                    idx=1;
                }
                ans[idx]=c;
                idx+=2;
                counter[i]-=1;
            }
        }

        return ans;
    }
};