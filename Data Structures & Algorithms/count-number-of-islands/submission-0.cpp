class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        unordered_map<string, int> vis;
        int count = 0;
        for(int i = 0; i< grid.size(); i++){
            for(int j = 0; j< grid[0].size(); j++){
                if(grid[i][j] == '1' && vis.find(to_string(i)+"#"+to_string(j)) == vis.end()){
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    vis[to_string(i)+"#"+to_string(j)] = 1;

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
                                if(vis.find(to_string(newrow)+"#"+to_string(newcol)) == vis.end()){
                                    vis[to_string(newrow)+"#"+to_string(newcol)] = 1;
                                    q.push({newrow, newcol});
                                }
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
