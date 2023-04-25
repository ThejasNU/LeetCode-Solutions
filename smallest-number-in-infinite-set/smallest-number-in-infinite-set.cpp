class SmallestInfiniteSet {
private:
    priority_queue<int,vector<int>,greater<int>> pq;
    unordered_map<int,int> m;
    int curInt;
public:
    SmallestInfiniteSet() {
        pq=priority_queue<int,vector<int>,greater<int>>();
        m.clear();
        curInt=1;
    }
    
    int popSmallest() {
        int ans;
        if(!pq.empty()){
            ans=pq.top();
            m.erase(ans);
            pq.pop();
        }
        else{
            ans=curInt;
            ++curInt;
        }
        return ans;
    }
    
    void addBack(int num) {
        if(curInt<=num || m.find(num)!=m.end()) return;
        pq.push(num);
        m[num]++;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */