class Solution {
public:

    vector<vector<int>> direction = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int ans = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    int cnt = 0;

                    q.push({i,j});
                    visited[i][j] = true;

                    while(!q.empty()){
                        pair<int,int> p = q.front();
                        q.pop();
                        cnt++;

                        for(vector<int>& v : direction){
                            int ni = p.first + v[0];
                            int nj = p.second + v[1];

                            if(ni < 0 || ni >=m || nj < 0 || nj >= n || grid[ni][nj] == 0
                                 || visited[ni][nj]){
                                continue;
                            }

                            q.push({ni,nj});
                            visited[ni][nj] = true;
                        }
                    }

                    ans = max(cnt, ans);

                }
            }
        }

        return ans;
    }
};