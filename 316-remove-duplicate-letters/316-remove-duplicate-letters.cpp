class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool> ar(26,false);
        int n = s.size();
        vector<int> li(26,0);
        for(int i = 0;i<n;i++){
            li[s[i]-'a'] = i;
        }
        stack<char> st;
        st.push(s[0]);
        ar[s[0]-'a'] = true;
        for(int i = 1;i<n;i++){
            int c = s[i]-'a';
            if(ar[c]){
                continue;
            }
            while(st.size() && s[i]<st.top()  && li[st.top()-'a']>i ){
                ar[st.top()-'a'] = false;
                st.pop();
               
            }
             st.push(s[i]);
            ar[c] = true;
           
        }
          string ans = "";
        while(st.size()){
            char c = st.top();
            ans.push_back(c);
            st.pop();
        }
      reverse(ans.begin(),ans.end());
        return ans;
    }
};