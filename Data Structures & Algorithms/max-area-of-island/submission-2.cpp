class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;    
        if(grid.size() == 0){
            return 0;
        }
        for(int i = 0; i< grid.size(); i++){
            for(int j = 0; j< grid[0].size(); j++){
                if(grid[i][j] == 1){
                    queue<pair<int,int>>q;
                    int count = 0;
                    q.push({i, j});
                    grid[i][j] = 0;

                    while(!q.empty()){
                        int row = q.front().first;
                        int col = q.front().second;
                        count++;
                        q.pop();
                        
                        int drow[] = {-1, 1, 0, 0};
                        int dcol[] = {0, 0, -1, 1};
                        
                        for(int i = 0; i< 4; i++){
                            int newrow = row + drow[i];
                            int newcol = col + dcol[i];

                            if(newrow >= 0 && newrow < grid.size()){
                                if(newcol >= 0 && newcol < grid[0].size() && grid[newrow][newcol] == 1){
                                    grid[newrow][newcol] = 0;
                                    q.push({newrow, newcol});
                                }
                            }
                        }
                    }

                    maxArea = max(maxArea, count);
                }
            }
        }

        return maxArea;
    }
};
