class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int,int>> que;
        vector<vector<int>> result(m, vector<int>(n, -1));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(mat[i][j] == 0){
                    que.push({i,j});
                    result[i][j] = 0;
                }

            }
        }

        vector<vector<int>> direction = {{-1,0}, {1,0}, {0,1}, {0,-1}};

        while(!que.empty()){
            
            int r = que.front().first;
            int c = que.front().second;
            que.pop();

            for(auto& dir : direction){
                int nr = r + dir[0];
                int nc = c + dir[1];

                if(nr >=0 && nr < m && nc >= 0 && nc < n && result[nr][nc] == -1){
                    result[nr][nc] = result[r][c] + 1;
                    que.push({nr,nc});
                }
            }

        }

        return result;

    }
};