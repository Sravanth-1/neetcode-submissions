class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rows(9, 0);
        vector<int> cols(9, 0);
        vector<int> subbox(9, 0);

        for(int i = 0; i< board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    int subboxnum = (i/3)*3 + (j/3);
                    if((rows[i] & (1 << num)) || (cols[j] & (1 << num)) || (subbox[subboxnum] & (1 << num))){
                        return false;
                    }
                    rows[i] |= (1 << num);
                    cols[j] |= (1 << num);
                    subbox[subboxnum] |= (1 << num);
                }
            }
        }

        return true;
    }
};

