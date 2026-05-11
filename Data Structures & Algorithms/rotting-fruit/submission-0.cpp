class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, pair<int,int>>> q;
        int count = 0;
        for(int i = 0; i< grid.size(); i++){
            for(int j = 0; j< grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({0,{i, j}});
                    count++;
                }
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }

        int mintime = 0;
        while(!q.empty()){
            int time = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            count--;
            mintime = max(time, mintime);
            int drow[] = {0, 0, -1, 1};
            int dcol[] = {1, -1, 0, 0};

            for(int i = 0; i< 4; i++){
                int newrow = row + drow[i];
                int newcol = col + dcol[i];
                if(newcol >= 0 && newcol < grid[0].size() && newrow >= 0 && newrow < grid.size()){
                    if(grid[newrow][newcol] == 1){
                        grid[newrow][newcol] = 2;
                        q.push({time+1, {newrow, newcol}});
                    }
                }
            }
        }

        if(count){
            return -1;
        }
        return mintime;

    }
};
