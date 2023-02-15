class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>ref,ans;
        while(k>0){
              int a = k%10;
            ans.push_back(a);
            k/=10;
        }
        reverse(begin(num),end(num));
        int i = 0,j=0,carry=0;
          int a = num.size();
            int b = ans.size();
        while(i<a and j<b){
            int c = num[i]+ans[j]+carry;
                int d = c%10;
             ref.push_back(d);
              carry = c/10;
            i++,j++;
 }
        while(i<a){
            int e = num[i]+carry;
              int h = e%10;
             ref.push_back(h);
            carry = e/10;
               i++;
      }
        while(j<b){
              int f = ans[j]+carry;
            int i = f%10;
            ref.push_back(i);
               carry = f/10;
            j++;
        }
        if(carry!=0) ref.push_back(carry);
           reverse(begin(ref),end(ref));
                 return ref;
      }
};