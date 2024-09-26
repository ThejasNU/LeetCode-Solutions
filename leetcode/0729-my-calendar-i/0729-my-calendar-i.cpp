class MyCalendar {
private:
    set<pair<int,int>> bookings;
public:
    MyCalendar() {
        bookings.clear();
    }
    
    bool book(int start, int end) {
        pair<int,int> booking{start,end};

        auto nextBooking = bookings.lower_bound(booking);
        if(nextBooking!=bookings.end() && nextBooking->first < end){
            return false;
        }

        if(nextBooking!=bookings.begin()){
            auto prevBooking= prev(nextBooking);
            if(prevBooking->second > start){
                return false;
            }
        }

        bookings.insert(booking);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */