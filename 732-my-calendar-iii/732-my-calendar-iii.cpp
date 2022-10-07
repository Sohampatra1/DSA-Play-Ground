class MyCalendarThree {
    map<int, int> m;
public:
    MyCalendarThree() {}
    
    int book(const int start, const int end) {
        ++m[start];
        --m[end];
        int ret = 0, a = 0;
        for (auto [_, count] : m)
            ret = max(ret, a += count);
        return ret;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */