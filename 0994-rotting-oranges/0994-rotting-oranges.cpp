class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> direction = {
            {1, 0},
            {-1, 0},
            {0, -1},
            {0, 1}
        };

        int fresh = 0;
        queue<pair<int,int>> que;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    que.push({i,j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int level = 0;

        while(!que.empty() && fresh > 0){
            int size = que.size();

            while(size--){
                int r = que.front().first;
                int c = que.front().second;
                que.pop();

                for(auto& dir : direction){
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                        fresh--;
                        que.push({nr,nc});
                        grid[nr][nc] = 2;
                    }
                }
            }

            level++;
        }

        return fresh == 0 ? level : -1;
    }
};