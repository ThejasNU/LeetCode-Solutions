class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        
        long long ans=0;
        int n=skill.size();
        int m=n/2;
        
        long long sum=skill[0]+skill[skill.size()-1];
        
        for(int i=0;i<m;++i){
            if(skill[i]+skill[n-i-1]==sum) ans+=skill[i]*skill[n-i-1];
            else return -1;
        }
        
        return ans;
    }
};