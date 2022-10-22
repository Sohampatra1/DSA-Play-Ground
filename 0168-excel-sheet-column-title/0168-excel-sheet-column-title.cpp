class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber){
            ans = char(65 + (columnNumber-1)%26) + ans;
            columnNumber = (columnNumber-1)/26;
        }
        return ans;
    }
};