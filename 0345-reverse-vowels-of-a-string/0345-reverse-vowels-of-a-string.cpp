class Solution {
public:
    string reverseVowels(string s) {
        vector<char> v;
        int n = s.size();

        for(int i=0;i<n;i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u'){
                v.push_back(s[i]);
            } else if(s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U'){
                v.push_back(s[i]);
            }
        }

        int k = v.size()-1;

        for(int i=0;i<n;i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u'){
                s[i] = v[k--];
            } else if(s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U'){
                s[i] = v[k--];
            }
        }
        return s;
    }
};