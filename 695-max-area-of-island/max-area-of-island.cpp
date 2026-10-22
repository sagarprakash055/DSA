class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int n = grid.size();
        int m = grid[0].size();

        int drow[] = {-1,0,1,0};       // Up,Right,Down,Left
        int dcol[] = {0,1,0,-1};

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){

                if(grid[row][col] == 1){
                int currentArea = 0;
                queue<pair<int,int>> q;
                q.push({row,col});
                grid[row][col] = 0;

                while(!q.empty()){
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    
                    currentArea++;

                    for(int i = 0; i < 4; i++){
                        int nrow = r + drow[i];
                        int ncol = c + dcol[i];

                        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1){
                            grid[nrow][ncol] = 0;
                            q.push({nrow,ncol});
                        }
                    }

                }
                maxArea = max(maxArea, currentArea);
                }
            }
        }
        return maxArea;
    }
};