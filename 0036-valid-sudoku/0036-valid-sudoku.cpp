class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int checkrow[9][9] = {0},
            checkcol[9][9] = {0},
            checkbox[3][3][9] = {0};
        
    for(int row=0; row < 9; row++){
        for(int col = 0 ;col < 9;col++){
            if(board[row][col] == '.') continue;
            int num = board[row][col] -'1';
			if(checkrow[row][num] || checkcol[num][col] || checkbox[row/3][col/3][num])
                return false;
			else checkrow[row][num] = checkcol[num][col] = checkbox[row/3][col/3][num] = true;
        }
    }
        return true;
    }
};