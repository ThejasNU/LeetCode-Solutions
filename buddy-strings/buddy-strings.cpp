class Solution{
public:
    bool buddyStrings(string s, string goal){
        if(s.size()!=goal.size()) return false;

        if(s==goal){
            unordered_set<char> temp(s.begin(),s.end());
            //check if duplicates are there, if yes return true
            return temp.size()<s.size();
        }

        int i=0,j=s.size()-1;
        while(i<j && s[i]==goal[i]) ++i;
        while(j>=0 && s[j]==goal[j]) --j;

        if(i<j) swap(s[i],s[j]);

        return s==goal;
    } 
};

class altSolution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()) return false;

        //if both are same, check if any char occurs atleast twice,so that swapping won't make any difference
        if(s==goal){
            vector<int> count(26,0);
            for(char c:s){
                count[c-'a']+=1;
                if(count[c-'a']==2) return true;
            }
            return false;
        }
        
        int firstIndex=-1,secondIndex=-1;
        for(int i=0;i<s.size();++i){
            if(s[i]!=goal[i]){
                if(firstIndex==-1) firstIndex=i;
                else if(secondIndex==-1) secondIndex=i;
                else return false;
            }
        }

        //only 1 char difference
        if(secondIndex==-1) return false;
        
        return s[firstIndex]==goal[secondIndex] && s[secondIndex]==goal[firstIndex];
    }
};