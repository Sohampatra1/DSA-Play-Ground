class Solution {
public:
    vector<int> v;
    void solve(int n,int num)
    {
        if(num>n)
        {
            return;
        }
        for(int i=0;i<=9;++i)
        {
            int k=num*10+i;
            if(k==0)
            {
                continue;
            }
            if(k>n)
            {
                break;
            }
            else
            {
                v.push_back(k);
            }
            solve(n,k);
        }
    }
    vector<int> lexicalOrder(int n) {
        solve(n,0);
        return v;
    }
};