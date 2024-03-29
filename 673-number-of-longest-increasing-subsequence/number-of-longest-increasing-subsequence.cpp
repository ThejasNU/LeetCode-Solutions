class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> length(n,1);
        vector<int> count(n,1);

        int maxLength=1;
        for(int i=n-2;i>=0;--i){
            for(int j=i+1;j<n;++j){
                if(nums[j]>nums[i]){
                    if(length[j]+1>length[i]){
                        length[i]=length[j]+1;
                        count[i]=count[j];
                    }
                    else if(length[j]+1==length[i]){
                        count[i]+=count[j];
                    }
                }
            }
            maxLength=max(maxLength,length[i]);
        }

        int totalCnt=0;
        for (int i=0;i<n;++i) {
            if (length[i]==maxLength)
                totalCnt+=count[i];
        }
        return totalCnt;
    }
};

class topDownSolution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> length(n,1);
        vector<int> count(n,1);

        function<void(int)> helper=[&](int idx){
            if(length[idx]!=1) return;

            for(int i=idx+1;i<n;++i){
                if(nums[i]>nums[idx]){
                    helper(i);
                    if(length[i]+1>length[idx]){
                        length[idx]=length[i]+1;
                        count[idx]=count[i];
                    }
                    else if(length[i]+1==length[idx]){
                        count[idx]+=count[i];
                    }
                }
            }
        };

        int maxLength=INT_MIN;
        for(int i=0;i<n;++i){
            helper(i);
            maxLength=max(maxLength,length[i]);
        }
        int totalCnt=0;
        for (int i=0;i<n;++i) {
            if (length[i]==maxLength)
                totalCnt+=count[i];
        }
        return totalCnt;
    }
};