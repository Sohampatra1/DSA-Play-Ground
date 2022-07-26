class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        unordered_map<char,char>m;
        m[')'] = '(';
        m['}'] = '{';
        m[']'] = '[';
        
        for(auto i : s) {
            if(i == '(' || i == '{' || i == '[') {
                st.push(i);
            }
            else {
                if(st.size() == 0 || st.top() !=  m[i]) return false;
                st.pop();
            }
        }
        return st.size() == 0;
    }
};