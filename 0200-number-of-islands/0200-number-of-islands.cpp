class Solution {
private:
    // Searches for 1's nearby an island tile
    void check_surrounding(int i, int j, vector<vector<char>>& grid){
        if(i != 0 && grid[i-1][j] == '1'){
            grid[i-1][j] = '0';
            check_surrounding(i-1, j, grid);
        }

        if(j != 0 && grid[i][j-1] == '1'){
            grid[i][j-1] = '0';
            check_surrounding(i, j-1, grid);
        }

        if(i < grid.size()-1 && grid[i+1][j] == '1'){
            grid[i+1][j] = '0';
            check_surrounding(i+1, j, grid);
        }

        if(j < grid[i].size()-1 && grid[i][j+1] == '1'){
            grid[i][j+1] = '0';
            check_surrounding(i, j+1, grid);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int i = 0, j = 0;
        int num_of_islands = 0;

        for(i = 0; i < grid.size(); i++){
            for(j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    check_surrounding(i, j, grid);
                    num_of_islands++;
                    
                }

            }
        }

        return num_of_islands;
    }
};