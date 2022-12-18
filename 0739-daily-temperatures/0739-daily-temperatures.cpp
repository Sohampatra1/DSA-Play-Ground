class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {

        stack <pair<int,int>> st;
        int sz = temp.size();

        vector<int> res(sz);
        res[sz-1] = 0;
        st.push({sz-1,temp[sz-1]});

        for(int i=sz-2; i>=0; i--){
            if(temp[i] < st.top().second){
                res[i] = st.top().first - i;
                st.push({i,temp[i]});
            } else {
                while(!st.empty()){
                    if(temp[i] < st.top().second){ 
                        res[i] = st.top().first - i;
                        st.push({i,temp[i]});
                        break;
                    }
                    st.pop();
                }
                if(st.empty()){
                    st.push({i,temp[i]});
                    res[i] = 0;
                }
            }
        }

        return res;
    }
};