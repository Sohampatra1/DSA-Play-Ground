class Solution {
public:
    vector<vector<int>> str2words;
    vector<vector<int>> words2str;
    int pre_stop;
    int max_len(int start, vector<int>& cnt, vector<string>&words){
        if(start >= str2words.size() || pre_stop == words.size())
            return 0;
        int max_ret = 0;
        vector<string>tried;
        for(int word : str2words[start]){
            if(!tried.empty() && words[word] == tried.back()){
                continue;
            }
            if(cnt[word] > 0){
                cnt[word]--;
                tried.push_back(words[word]);
                max_ret = max(max_ret, max_len(start + words[word].size(), cnt, words) + 1);
                cnt[word]++;
            }
        }
        pre_stop = max(pre_stop, max_ret);
        return max_ret;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words.size(), slen = s.size(), sum = 0;;
        sort(words.begin(), words.end());
        str2words = vector<vector<int>>(slen);
        vector<string> uniquewords;
        vector<int> cnt;
        for(int i = 0; i < len; i++){
            sum += words[i].size();
            if(i > 0 && words[i] == words[i - 1]){
                cnt[cnt.size() - 1]++;
                continue;
            }
            int find = s.find(words[i]);
            words2str.push_back({});
            while(find != -1){
                str2words[find].push_back(cnt.size());
                words2str[cnt.size()].push_back(find);
                find = s.find(words[i], find + 1);
            }
            uniquewords.push_back(words[i]);
            cnt.push_back(1);
        }
        vector<int> ret;
        for(int i = 0; i <= slen - sum; i++){
            vector<int> tmp = cnt;
            pre_stop = 0;
            if(max_len(i, tmp, uniquewords) == len)
                ret.push_back(i);
        }
        return ret;
    }
};