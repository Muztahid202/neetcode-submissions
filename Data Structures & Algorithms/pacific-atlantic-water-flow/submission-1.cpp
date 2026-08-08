class Solution {
public:
     vector<vector<int>> directions{{1,0}, {-1,0}, {0,1}, {0,-1}};

    void dfs(vector<vector<int>>& heights, int m, int n, int i, int j, int prevHeight, vector<vector<int>>& visited){
        if(i < 0 || j < 0 || i >= m || j >= n) return;

        if(visited[i][j] == 1) return;

        if(heights[i][j] < prevHeight) return;

        visited[i][j] =  1;

        for(auto& dir : directions){
            dfs(heights, m, n, i + dir[0], j + dir[1], heights[i][j], visited);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> visitedP(m, vector<int>(n, 0));
        vector<vector<int>> visitedA(m, vector<int>(n, 0));

        for(int j = 0; j < n; j++){
            dfs(heights, m, n, 0, j, heights[0][j], visitedP); //strating from the top row
            dfs(heights, m, n, m-1, j, heights[m-1][j], visitedA); // staring from the bottom row 
        }

        //starting from the last row for finding out places which will lead to atlantic
        for(int i = 0; i < m; i++){
            dfs(heights, m, n, i, 0, heights[i][0], visitedP);//staring from the left col
            dfs(heights,m, n, i, n-1, heights[i][n-1], visitedA);//starting from the right col
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(visitedP[i][j] == 1 && visitedA[i][j] == 1) res.push_back({i,j});
            }
        }
        return res;
    }
};
