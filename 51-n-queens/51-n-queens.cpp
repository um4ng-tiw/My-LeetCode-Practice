class Solution {
public:
    vector<vector<string>> ans;
    
    bool isSafe(int row, int col, vector<string>&board, int n){
        int rowCopy = row;
        int colCopy = col;
        
        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        
        col = colCopy;
        
        while(col >= 0 && row >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
            row--;
        }
        
        row = rowCopy;
        col = colCopy;
        
        while(col >= 0 && row < n){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        
        return true;
    }
    
    void solve(int col, vector<string>&board, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row <n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(col+1, board, n);
                board[row][col] = '.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s(n, '.');
        
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        
        solve(0, board, n);
        
        return ans;
    }
};