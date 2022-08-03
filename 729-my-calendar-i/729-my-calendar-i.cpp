class MyCalendar {
public:
    map<int, int> events;
    MyCalendar() {
    
    }
    
    bool book(int start, int end) {
        for(pair<int, int> p:events) {
            if(max(p.first, start) < min(p.second, end))
                return false;
        }
        events.insert({start, end});
        return true;
    }
};