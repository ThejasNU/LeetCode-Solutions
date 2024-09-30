class CustomStack {
private:
    int maxLen;
    vector<int> store;
    int top;

public:
    CustomStack(int maxSize) {
        maxLen = maxSize;
        store.resize(maxSize);
        top = -1;
    }

    void push(int x) {
        if(top==maxLen-1){
            return;
        }

        store[++top]=x;
    }

    int pop() {
        if(top==-1){
            return -1;
        }

        return store[top--];
    }

    void increment(int k, int val) {
        for(int i=0;i<min(k,top+1);++i){
            store[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */