class Solution {
public:
    vector<vector<int>> res;
    vector<int> done;
    bool chosen[21];
    void create(int cnt,int n,int k,int id)
    {
        if(cnt==k)
        {
            res.push_back(done);
        }
        for(int i=id;i<=n;++i)
        {
            if(!chosen[i])
            {
                done.push_back(i);
                chosen[i]=true;
                create(cnt+1,n,k,i+1);
                done.pop_back();
                chosen[i]=false;
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        memset(chosen,false,sizeof(chosen));
        create(0,n,k,1);
        return res;
    }
    
};