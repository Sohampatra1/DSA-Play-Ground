class Solution {
public:
    void dfs(int node1,vector<int>& a,vector<int>& edges){
         while(edges[node1]!=-1 && a[edges[node1]]==-1)
        {
        int node=edges[node1];
            a[node]=a[node1]+1;
              node1=node;  }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
          int n=edges.size();
        vector<int> a(n,-1),b(n,-1);
          a[node1]=0;
        b[node2]=0;
           int res=INT_MAX;
        int resNode=-1;
    dfs(node1,a,edges);
          dfs(node2,b,edges);
        for(int i=0;i<n;i++)
        {
            if(a[i]!=-1 && b[i]!=-1 && max(a[i],b[i])<res)
            {
                res=max(a[i],b[i]);
                  resNode=i;
               }
        }
        return resNode;
    }
};