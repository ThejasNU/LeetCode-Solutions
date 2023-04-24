class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());
        int n1,n2,dif;
        while(pq.size()>1){
            n1=pq.top();
            pq.pop();
            n2=pq.top();
            pq.pop();
            dif=abs(n1-n2);
            if(dif>0) pq.push(dif);
        }
        if(pq.empty()) return 0;
        else return pq.top();
    }
};