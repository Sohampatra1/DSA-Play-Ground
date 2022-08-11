class Solution {
public:
    int m;
    int n;
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        char firstChar = word[0];

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == firstChar && explore(board, i, j, 0, word)) { 
                    return true;
                }
            }
        }
        return false;
    }
    
    bool explore(vector<vector<char>> &board, int i, int j, int currChar, string &word) {
        if(i >= m || j >= n || i < 0 || j < 0) return false;
        if(board[i][j] != word[currChar]) return false;
        if(currChar == word.size()-1) return true;
        board[i][j] = '.';
        
        if(explore(board, i+1, j, currChar+1, word)) return true;
        if(explore(board, i-1, j, currChar+1, word)) return true;
        if(explore(board, i, j+1, currChar+1, word)) return true;
        if(explore(board, i, j-1, currChar+1, word)) return true;
        board[i][j] = word[currChar];
        return false;
    }
};