class Solution {
public:

    void dfs(vector<vector<int>>& grid, int i, int j, int& sum) {
        int row = grid.size();
        int col = grid[0].size();
    
        if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0) {
            return;
        }

        sum++;
        grid[i][j] = 0; 
        dfs(grid, i - 1, j, sum);
        dfs(grid, i + 1, j, sum);
        dfs(grid, i, j - 1, sum);
        dfs(grid, i, j + 1, sum);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int areaLand = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                int sum =0;
                if(grid[i][j]==1)
                {
                    dfs(grid,i,j,sum);
                }
                areaLand = max(sum,areaLand);
            }
        }
        return areaLand;

    }
};
