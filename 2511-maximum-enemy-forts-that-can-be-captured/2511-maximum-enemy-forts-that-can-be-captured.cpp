class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n=forts.size();
        vector<int> ind;
        for(int i=0;i<n;++i){
            if(forts[i]==1) ind.push_back(i);
        }
        
        int ans=0;
        for(int i:ind){
            int j=i+1;
            int temp=0;
            while(j<n){
                if(forts[j]!=0){
                    if(forts[j]==-1) ans=max(ans,temp);
                    break;
                }
                j++;
                temp++;
            }
            
            temp=0;
            j=i-1;
            while(j>=0){
                if(forts[j]!=0){
                    if(forts[j]==-1) ans=max(ans,temp);
                    break;
                }
                j--;
                temp++;
            }
            if(j>=0 && forts[j]==-1) ans=max(ans,temp);
        }
        return ans;
    }
};