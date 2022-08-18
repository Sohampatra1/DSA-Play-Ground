class Solution {
public:
    int minSetSize(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        multiset<int,  greater<int> > s;
        int count = 1, n=arr.size();
        for(int i=1;i<n;i++) {
            if(arr[i] == arr[i-1])
                count++;
            else {
                s.insert(count);
                count = 1;
            }
            if(i == n-1 && arr[i] == arr[i-1]) {
                s.insert(count);
            }
        }
        count = 0;
        int temp = n;
        for(auto i: s) {
            n -= i;
            count++;
            if(n <= temp/2) {
                break;
            }
        }
        return count;
    }
};