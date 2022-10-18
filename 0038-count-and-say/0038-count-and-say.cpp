class Solution {
public:
    
    string countAndSay(int n) {
       
        list <int> lst;
        lst.push_back(1);
        int i=1;
        for(int i=1;i<n;i++)
        {
            int j=0,N=lst.size(),count;
            int element;
            while(j<N){
                element = lst.front();
                count =1;
                lst.pop_front();
                j++;
                while(j<N && element == lst.front() )
                {
                    lst.pop_front();
                    count++;
                    j++;
                }
                lst.push_back(count);
                lst.push_back(element);
            }
         
        }
        string s="";
            for(auto it=lst.begin();it!=lst.end();it++)
                s+=to_string(*it);
        return s;
    }
};