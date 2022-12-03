class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        for(auto i :s)
        {
            m[i]++;
        }

        map<int,string> mp;
        string answer = "";
        for(map<char,int>::iterator it =m.begin();it!=m.end();it++){
            string temp(it->second,it->first);
            mp[it->second]+=temp;
        }

        for(map<int,string>:: reverse_iterator it =mp.rbegin();it!=mp.rend();it++){
           answer+=it->second;
        }



        return answer;

        
        
        
    }
};