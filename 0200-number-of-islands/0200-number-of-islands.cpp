class Solution {
public:

    vector<int> parent;
    vector<vector<int>> direction = {{1,0}, {0,1}};

    int find(int x){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    int unite(int x, int y){

        int px = find(x);
        int py = find(y);

        if(px == py){
            return false;
        }

        parent[py] = px;

        return true;
    }

    

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        parent.resize(m*n);
        int island = 0;

        for(int i=0; i<m*n; i++){
            parent[i] = i;
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    island++;
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    int idx1 = i * n + j;

                    for(auto& v : direction){
                        int ni = i + v[0];
                        int nj = j + v[1];

                        if(ni < m && nj < n && grid[ni][nj] == '1'){
                            int idx2 = ni * n +nj;

                            if(unite(idx1 , idx2)){
                                island--;
                            }
                        }
                    }

                }
            }
        }

        return island;
    }
};