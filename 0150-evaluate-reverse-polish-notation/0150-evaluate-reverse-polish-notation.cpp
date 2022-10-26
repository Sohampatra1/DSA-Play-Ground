class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        for (string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                long op2 = st.top();
                st.pop();
                long op1 = st.top();
                st.pop();
                if (token == "+") st.push(op1 + op2);
                else if (token == "-") st.push(op1 - op2);
                else if (token == "*") st.push(op1 * op2);
                else if (token == "/") st.push(op1 / op2);
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};