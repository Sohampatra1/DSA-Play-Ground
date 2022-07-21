class StockSpanner {
public:
    stack<pair<int,int>>stk;
    int i;
    StockSpanner() {
        i=0;
    }
    
    int next(int price) {
        int ans;
        while(stk.size()!=0 && stk.top().first <= price  ){
            stk.pop();
        }
        if(stk.size()==0){
            ans = -1;
        }
        else{
            ans = stk.top().second;
        }
        stk.push({price, i});
        ans = i- ans; // curr indx - NGLidx
        i++;
        return ans;
    }
};
