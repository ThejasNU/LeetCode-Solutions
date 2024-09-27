class MyCalendarTwo {
private:
    map<int, int> m;

public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        m[start] += 1;
        m[end] -= 1;

        int prefix = 0;
        for (auto& [k, cnt] : m) {
            prefix += cnt;

            if (prefix > 2) {
                m[start] -= 1;
                m[end] += 1;
                if (m[start] == 0) {
                    m.erase(start);
                }
                if (m[end] == 0) {
                    m.erase(end);
                }

                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */