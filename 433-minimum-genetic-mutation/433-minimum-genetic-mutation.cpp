class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        int ans=0;
        vector<char> let ={'A','C','G','T'};
        queue<pair<string,int>> q;
        q.push({start,0});
        map<string,bool> isVis;
        isVis[start]=true;
        while(!q.empty()){
            auto temp = q.front();
            string s = temp.first;
            int steps = temp.second;
            if(s==end){
                return steps;
            }
            q.pop();
            for(int i = 0; i<s.length();i++){
                string t = s;
                for(int j=0;j<4;j++){
                    t[i]=let[j];
                    if(find(bank.begin(),bank.end(),t)!=bank.end() && !isVis[t]){
                        q.push({t,steps+1});
                        isVis[t]=true;
                    }
                }
            }
            
        }
        return -1;
    }
};