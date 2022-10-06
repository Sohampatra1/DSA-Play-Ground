class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mpp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {

        mpp[key].push_back(make_pair(timestamp,value));
    }
    
    string get(string key, int timestamp) {
        
        if(mpp.find(key)==mpp.end())  return "";
        
        int l=0,r=mpp[key].size()-1;

        if(mpp[key][0].first > timestamp) return "";

        while(r >= l)
        {
            int mid = l+(r-l)/2;

            if(mpp[key][mid].first == timestamp) return mpp[key][mid].second;

            if(mpp[key][mid].first < timestamp) l = mid+1;
            
            else r = mid-1;
        }

        return mpp[key][r].second;
    }
};
