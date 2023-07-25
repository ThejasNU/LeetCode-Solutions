class MedianFinder {
public:
    multiset<int> s;
    MedianFinder() {
        s.clear();
    }
    
    void addNum(int num) {
        s.insert(num);
    }
    
    double findMedian() {
        int n=s.size();
        int mid=n/2;
        auto it=s.begin();
        advance(it,mid);
        double ans=*it;
        if(n%2==0){
            --it;
            ans+=*it;
            ans/=2.0;
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */