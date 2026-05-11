class Solution {
public:
    void bfs(queue<pair<int,int>> &q, vector<vector<int>> &reach,vector<vector<int>>& heights){
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int drow[] = {1, -1, 0, 0};
            int dcol[] = {0, 0, 1, -1};

            for(int i = 0; i< 4; i++){
                int newrow = row + drow[i];
                int newcol = col + dcol[i];
                if(newrow >= 0 && newrow < heights.size() && newcol >= 0 && newcol < heights[0].size()){
                    if(heights[newrow][newcol] >= heights[row][col] && reach[newrow][newcol] == 0){
                        reach[newrow][newcol] = 1;
                        q.push({newrow, newcol});
                    }
                }
            }
        }
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> pacificreach(heights.size(), vector<int>(heights[0].size(), 0));
        vector<vector<int>> atlanticreach(heights.size(), vector<int>(heights[0].size(), 0));
        
        queue<pair<int,int>> pacificq, atlanticq;

        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
               if(i == 0 || j == 0){
                pacificreach[i][j] = 1;
                pacificq.push({i, j});
               }
               if(i == heights.size()-1 || j == heights[0].size()-1){
                atlanticreach[i][j] = 1;
                atlanticq.push({i, j});
               }
            }
        }

        bfs(pacificq, pacificreach, heights);
        bfs(atlanticq, atlanticreach, heights);

        vector<vector<int>> reachedcells;

        for(int i = 0; i< heights.size(); i++){
            for(int j = 0; j< heights[0].size(); j++){
                if(pacificreach[i][j] == 1 && atlanticreach[i][j] == 1){
                    reachedcells.push_back({i, j});
                }
            }
        }

        return reachedcells;
    }
};
