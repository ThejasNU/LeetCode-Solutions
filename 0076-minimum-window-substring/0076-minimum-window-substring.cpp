class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s.size()==0 || t.size()==0) return "";
        
        unordered_map<char,int> m;
        
        for(int i=0;i<t.size();++i){
            m[t[i]]++;
        }
        
        int required=m.size();
        int l=0,r=0;
        
        int formed=0;
        
        unordered_map<char,int> windowCounts;
        
        //window length,left,right
        int ans[]={-1,0,0};
        
        while(r<s.size()){
            char c=s[r];
            windowCounts[c]++;
            
            if(windowCounts[c]==m[c]) formed++;
            
            while(l<=r && formed==required){
                c=s[l];
                
                if(ans[0]==-1 || r-l+1<ans[0]){
                    ans[0]=r-l+1;
                    ans[1]=l;
                    ans[2]=r;
                }
                windowCounts[c]--;
                
                if(windowCounts[c]<m[c]) formed--;
                
                l++;
            }
            r++;
        }
        
        return ans[0]==-1?"":s.substr(ans[1],ans[2]-ans[1]+1);
    }
};