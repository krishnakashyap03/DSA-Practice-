class Solution {
public:
    int n, m;
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void dfs(vector<vector<char>>& board, int i , int j){
        board[i][j] = 'T';

        for(vector<int> &dir: directions){
            int x = i + dir[0];
            int y = j + dir[1];

            if(isValid(x , y) && board[x][y] == 'O'){
                dfs(board, x, y);
            }
        }
    }
    bool isValid(int i ,int j){
        return i < n  && i >= 0 && j < m && j >= 0;
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        // marking every border row cell == 'O' 
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O'){
                dfs(board, i, 0);
            }
            if(board[i][m - 1] == 'O'){
                dfs(board, i, m - 1);
            }
        }

        // marking every border column cell == 'O'
        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O'){
                dfs(board, 0, i);
            }
            if(board[n - 1][i] == 'O'){
                dfs(board,n - 1, i);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                } else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};