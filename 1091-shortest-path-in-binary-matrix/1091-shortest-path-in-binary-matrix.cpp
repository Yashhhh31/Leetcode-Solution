class Solution {
public:
    vector<pair<int,int>> direction = {
        {1,0}, {0,1}, {0,-1}, {-1,0},
        {-1,-1}, {-1,1}, {1,-1}, {1,1}
    };

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0] != 0 || grid[m-1][n-1] != 0) return -1;

        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;

        while(!q.empty()){
            auto[r, c] = q.front();
            q.pop();

            if(r == m-1 && c == n-1) return grid[r][c];

            for(auto& dir : direction){
                int nr = r + dir.first;
                int nc = c + dir.second;

                if(nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] != 0) continue;

                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr,nc});

            }
        }

        return -1;
    }
};