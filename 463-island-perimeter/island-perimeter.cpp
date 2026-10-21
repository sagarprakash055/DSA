class Solution {
    private:
    int bfs(int startrow, int startcol, vector<vector<int>> & vis, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vis[startrow][startcol] = 1;
        queue<pair<int,int>>q;
        q.push({startrow, startcol});
        int perimeter = 0;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow < 0 || nrow >= n || ncol < 0 || ncol >= m || grid[nrow][ncol] == 0){
                    perimeter++;
                }
                else if(grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        return perimeter;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int contri;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && grid[row][col] == 1){
                   return bfs(row,col,vis,grid);
                }
            }
        }
        return 0;
    }
};