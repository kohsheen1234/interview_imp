
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numIslands = 0;
        int rows = grid.size();
        if (rows == 0) return 0; // Edge case
        int cols = grid[0].size();

        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        int dir_x[4] = {1, -1, 0, 0};
        int dir_y[4] = {0, 0, 1, -1};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Start BFS if the cell is '1' and not visited
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                    numIslands++;

                    // Begin BFS traversal here
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = 1;

                    while (!q.empty()) {
                        auto cell = q.front();
                        q.pop();
                        int x = cell.first;
                        int y = cell.second;

                        for (int k = 0; k < 4; k++) {
                            int newX = x + dir_x[k];
                            int newY = y + dir_y[k];

                            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols &&
                                grid[newX][newY] == '1' && visited[newX][newY] == 0) {

                                q.push({newX, newY});
                                visited[newX][newY] = 1;
                            }
                        }
                    }
                }
            }
        }
        return numIslands;
    }
};
