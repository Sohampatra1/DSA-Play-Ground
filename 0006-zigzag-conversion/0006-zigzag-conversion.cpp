class Solution {
public:
    string convert(string s, int numRows) {
         vector<vector<char>> vec( numRows , vector<char> (s.size(), ';')); 
          if(numRows ==1)
            return s;
       int i=0;
          int curr_row=0;
             int curr_col=0;
         while(i<s.size())
         {
        if(curr_row ==0){
               
                 while(i<s.size() && curr_row<numRows)
                 {
              vec[curr_row][curr_col] = s[i];
              i++;
             curr_row++;
                 }
                curr_row -=2;
                  curr_col++;
             
             }

             while(i<s.size() && curr_row>=1)
             {
               
                 vec[curr_row][curr_col] = s[i];
                 curr_row--;
                     curr_col++;
                i++;
                 }
                     }

         string ans ="";
            for(int k = 0; k < numRows; k++)
           {
                for(int j = 0; j < curr_col; j++)
        {
                if(vec[k][j]!=';'){
                ans+=vec[k][j];
            }
        }
        }
                return ans;

        
        }
};