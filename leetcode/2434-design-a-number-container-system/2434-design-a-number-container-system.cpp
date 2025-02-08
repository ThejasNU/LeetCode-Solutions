class NumberContainers {
private:
    unordered_map<int, int> idxNum;
    unordered_map<int, set<int>> numIdxs;

public:
    NumberContainers() {
        idxNum.clear();
        numIdxs.clear();
    }

    void change(int index, int number) {
        if (idxNum.find(index) != idxNum.end()) {
            int prev = idxNum[index];
            numIdxs[prev].erase(index);
            if (numIdxs[prev].empty()) {
                numIdxs.erase(prev);
            }
        }
        idxNum[index] = number;
        numIdxs[number].insert(index);
    }

    int find(int number) {
        if (numIdxs.find(number) != numIdxs.end()) {
            return *numIdxs[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */