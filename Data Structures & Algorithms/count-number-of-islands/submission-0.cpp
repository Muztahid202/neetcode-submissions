class Solution {
public:
    vector<vector<int>> directions{{1,0}, {-1,0}, {0,1}, {0,-1}};
    void dfs(vector<vector<char>>& grid, int row, int col){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == '#') return;

        if(grid[row][col] == '0') return;
        
        grid[row][col] = '#';

        for(auto& dir: directions){
            dfs(grid, row + dir[0], col + dir[1]);
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};
