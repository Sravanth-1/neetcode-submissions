class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if(grid.size() == 0){
            return;
        }
        queue<pair<int, pair<int, int>>>  q;
        for(int i = 0; i< grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    q.push({0, {i, j}});
                }
            }
        }

        while(!q.empty()){
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            int drow[] = {1, -1, 0, 0};
            int dcol[] = {0, 0, 1, -1};

            for(int k = 0; k< 4; k++){
                int newrow = row+drow[k];
                int newcol = col+dcol[k];
                if(newrow >= 0 && newrow < grid.size() && newcol >= 0 && newcol < grid[0].size()){
                    if(grid[newrow][newcol] == INT_MAX){
                        grid[newrow][newcol] = dis+1;
                        q.push({dis+1, {newrow, newcol}});
                    }
                }
            }
        }
        return;
    }
};
