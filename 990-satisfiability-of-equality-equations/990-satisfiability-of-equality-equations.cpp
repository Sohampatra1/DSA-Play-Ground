class Solution {
     vector<int> par,size;
public:    
    int findPar(int node)
    {
        if(par[node]==node)
            return node;
        return par[node] = findPar(par[node]);
    }
    void unionFun(int a,int b)
    {
        a = findPar(a);
        b = findPar(b);
        if(a==b)
            return;
        if(size[a]>size[b])
        {
            par[a]=par[b];
            size[a]++;
        }
        else{
            par[b]=par[a];
            size[b]++;
        }
    }
    bool equationsPossible(vector<string>& eq) {
        int i,j,n=eq.size();
        par.resize(26);
        size.resize(26);
        
        for(i=0;i<26;i++)
        { par[i]=i; size[i]=1;}
        
        for(auto it: eq)
        {
            if(it[1]=='=')
                unionFun(it[0]-'a',it[3]-'a');
        }
         for(auto it: eq)
        {
            if(it[1]=='!')
            {
                if(findPar(it[0]-'a')==findPar(it[3]-'a'))
                    return 0;
            }
        }
        return 1;
    }
};