class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        int rows = board.size();
        int cols = board[0].size();

        for(int i = 0; i< cols; i++){
           if(board[0][i] == 'O'){
            board[0][i] = 'A';
            q.push({0, i});
           }
           if(board[rows-1][i] == 'O'){
            board[rows-1][i] = 'A';
            q.push({rows-1, i});
           }
        }

        for(int i = 0; i< rows; i++){
            if(board[i][0] == 'O'){
            board[i][0] = 'A';
            q.push({i, 0});
           }
           if(board[i][cols-1] == 'O'){
            board[i][cols-1] = 'A';
            q.push({i, cols-1});
           }
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int drow[] = {0, 0, 1, -1};
            int dcol[] = {1, -1, 0, 0};

            for(int i = 0; i< 4; i++){
                int newrow = row + drow[i];
                int newcol = col + dcol[i];
                if(newrow >= 0 && newrow < rows && newcol >= 0 && newcol < cols){
                    if(board[newrow][newcol] == 'O'){
                       board[newrow][newcol] = 'A';
                       q.push({newrow,newcol});
                    }
                }
            }
        }


        for(int i = 0; i< rows; i++){
            for(int j = 0; j< cols; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }

                if(board[i][j] == 'A'){
                    board[i][j] = 'O';
                }
            }
        }

        return;
    }
};
