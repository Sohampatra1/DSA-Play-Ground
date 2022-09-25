class MyCircularQueue {
public:
    deque<int> q;
    int t1;
    MyCircularQueue(int k) {
        q.clear();
        t1=k;
    }
    
    bool enQueue(int value) {
        if(q.size()<t1)
        {
            q.push_back(value);
            return 1;
        }
        return 0;
    }
    
    bool deQueue() {
        if(q.size()==0)
            return 0;
        q.pop_front();
        return 1;
    }
    
    int Front() {
        if(q.empty())
            return -1;
        return q.front();
    }
    
    int Rear() {
        if(q.empty())
            return -1;
        return q.back();
    }
    
    bool isEmpty() {
        return (q.empty());
    }
    
    bool isFull() {
        return q.size()==t1;
    }
};
