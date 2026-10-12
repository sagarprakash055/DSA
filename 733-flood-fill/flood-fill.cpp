class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int originalcolor = image[sr][sc];

        if(originalcolor == color) return image;

        vector<vector<int>> vis (n, vector<int>(m,0));
        vis[sr][sc] = 1;
        image[sr][sc] = color;
        queue <pair<int,int>> q;
        q.push({sr,sc});

         // Define the 4 allowed directions: Up, Right, Down, Left

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && image[nrow][ncol] == originalcolor){
                    image[nrow][ncol] = color;
                    q.push({nrow,ncol});
                }
            }
        }
        return image;
    }
};