class Solution {
public:
    int n,m;
    int cnt = 0;
    vector<vector<int>> direction = {{1,0}, {0,1}, {-1,0}, {0, -1}};
    vector<vector<bool>> visited;

    void solve(vector<vector<char>>& grid, int i, int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = true;

        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();

            for(vector<int>& v : direction){
                int new_i = p.first + v[0];
                int new_j = p.second + v[1];

                if(new_i < 0 || new_i >= m || new_j < 0 || new_j >= n || grid[new_i][new_j] == '0')
                    continue;

                if(!visited[new_i][new_j]){
                    q.push({new_i,new_j});
                    visited[new_i][new_j] = true;
                }
            }
        }

        cnt++;
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        visited.assign(m,vector<bool>(n, false));

       for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == '1' && visited[i][j] == false){
                solve(grid,i,j);
            }
        }
       }

       return cnt;

    }
};