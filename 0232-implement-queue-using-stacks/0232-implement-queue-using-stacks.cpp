class MyQueue {
    stack<int> st;
private:
    
    void insertAtBottom(stack<int> &st, int x)
    {
        if (st.size() == 0)
        {
            st.push(x);
            return;
        }
        int num = st.top();
        st.pop();
        insertAtBottom(st, x);
        st.push(num);
    }
public:
    void push(int x) {
        insertAtBottom(st, x);
    }
    
    int pop() {
        if (!st.empty())
        {
            int ans = st.top();
            st.pop();
            return ans;
        }
        else
        {
            return -1;
        }
    }
    
    int peek() {
        if (!st.empty())
        {
            return st.top();
        }
        else
        {
            return -1;
        }
    }
    
    bool empty() {
        if (st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */