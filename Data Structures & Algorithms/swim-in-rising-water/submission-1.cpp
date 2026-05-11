class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int,int>>,
                       vector<pair<int, pair<int,int>>>,
                       greater<pair<int, pair<int,int>>>> q;

        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));

        q.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;
        int drow[] = {1, -1, 0, 0};
        int dcol[] = {0, 0, -1, 1};
        while(!q.empty()){
            int maxtill = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();

            if(row == grid.size()-1 && col == grid[0].size()-1){
                return maxtill;
            } 
            
            for(int i = 0; i< 4; i++){
                int newrow = row+ drow[i];
                int newcol = col+ dcol[i];

                if(newrow >= 0 && newrow < grid.size() && newcol >= 0 && newcol < grid[0].size() && !vis[newrow][newcol]){
                    q.push({max(maxtill, grid[newrow][newcol]), {newrow, newcol}});
                    vis[newrow][newcol] = 1;
                }
            }

        }
    }
};
