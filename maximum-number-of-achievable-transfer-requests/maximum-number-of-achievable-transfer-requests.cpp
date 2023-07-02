class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int ans=0;
        int transfers[n];
        int lastBitMask=(1<<requests.size());
        for(int bitmask=0;bitmask<lastBitMask;++bitmask){
            memset(transfers,0,sizeof(transfers));
            int numSetBits=__builtin_popcount(bitmask);
            if(numSetBits<=ans) continue;
            
            int cur=bitmask,idx=requests.size()-1;
            while(cur>0){
                if(cur&1){
                    transfers[requests[idx][0]]-=1;
                    transfers[requests[idx][1]]+=1;
                }
                cur>>=1;
                --idx;
            }

            if(count(transfers,transfers+n,0)==n) ans=numSetBits;
        }
        return ans;
    }
};

class backtrackingSolution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> transfers(n,0);
        int ans=helper(n,0,requests,transfers,0);
        return ans==INT_MIN?0:ans;
    }

    int helper(int n,int idx,vector<vector<int>>& requests,vector<int>& transfers,int numOfRequests){
        if(idx==requests.size()){
            if(count(transfers.begin(),transfers.end(),0)==n) return numOfRequests;
            else return INT_MIN;
        }

        int ans=INT_MIN;
        //ignore the request
        ans=max(ans,helper(n,idx+1,requests,transfers,numOfRequests));
        
        //consider the request
        transfers[requests[idx][0]]-=1;
        transfers[requests[idx][1]]+=1;
        ans=max(ans,helper(n,idx+1,requests,transfers,numOfRequests+1));
        //backtrack
        transfers[requests[idx][0]]+=1;
        transfers[requests[idx][1]]-=1;
        return ans;
    }
};