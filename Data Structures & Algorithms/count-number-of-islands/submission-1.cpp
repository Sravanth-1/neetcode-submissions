class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i< grid.size(); i++){
            for(int j = 0; j< grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    grid[i][j] = 0;
                    while(!q.empty()){
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();
                        int drow[] = {-1,1,0,0};
                        int dcol[] = {0, 0,-1, 1};

                        for(int k = 0; k< 4; k++){
                            int newrow = row + drow[k];
                            int newcol = col + dcol[k];

                            if(newrow >= 0 && newrow < grid.size() && newcol >= 0 && newcol < grid[0].size() && grid[newrow][newcol] == '1'){
                                grid[newrow][newcol] = 0;
                                q.push({newrow, newcol});
                            }
                        }
                    }
                    count++;
                }
                
            }
        }

        return count;
    }
};
