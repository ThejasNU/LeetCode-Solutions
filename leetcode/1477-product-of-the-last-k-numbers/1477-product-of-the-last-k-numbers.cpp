class ProductOfNumbers {
public:
    ProductOfNumbers() {
        prefix.resize(1, 1);
        size = 0;
    }

    void add(int num) {
        if (num == 0) {
            prefix.resize(1, 1);
            size = 0;
        } else {
            prefix.push_back(prefix.back() * num);
            ++size;
        }
    }

    int getProduct(int k) {
        if (k > size) {
            return 0;
        }
        return prefix[size] / prefix[size - k];
    }

private:
    vector<int> prefix;
    int size;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */