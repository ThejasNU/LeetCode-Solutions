class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n=spells.size();
        int m=potions.size();
        int maxPotion=potions[m-1];
        vector<int> ans(n);
        for(int i=0;i<n;++i){
            long long minRequired=ceil((1.0*success)/spells[i]);
            if(minRequired>maxPotion){
                ans[i]=0;
                continue;
            }
            auto index=lower_bound(potions.begin(),potions.end(),minRequired) - potions.begin();
            ans[i]=m-index;
        }
        return ans;
    }
};


class altSolution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n=spells.size();
        int m=potions.size();
        vector<int> ans(n);
        for(int i=0;i<n;++i){
            int l=0;
            int r=m-1;
            while(l<r){
                int mid=(l+r)/2;
                long long cur=spells[i]*1LL*potions[mid];
                if(cur<success){
                    l=mid+1;
                }
                else{
                    r=mid;
                }
            }

            if(l==m-1 && spells[i]*1LL*potions[l]<success) ans[i]=0;
            else ans[i]=m-l;
        }
        return ans;
    }
};