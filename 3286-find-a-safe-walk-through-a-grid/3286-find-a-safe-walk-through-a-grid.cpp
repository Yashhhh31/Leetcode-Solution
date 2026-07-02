class Solution {
public:

    vector<pair<int,int>> direction = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> result(m,vector<int>(n,INT_MAX));
        result[0][0] = grid[0][0];

        deque<pair<int,int>> deq;
        deq.push_back({0,0});

        while(!deq.empty()){
            auto[r,c] = deq.front();
            deq.pop_front();

            for(pair<int,int>& p : direction){
                int nr = r + p.first;
                int nc = c + p.second;

                if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                if(result[r][c] + grid[nr][nc] < result[nr][nc]){
                    result[nr][nc] = result[r][c] + grid[nr][nc];

                    if(grid[nr][nc] == 0){
                        deq.push_front({nr,nc});
                    }else{
                        deq.push_back({nr,nc});
                    }
                }
            }
        }

        int X = result[m-1][n-1];

        return health - X >= 1;
    }
};