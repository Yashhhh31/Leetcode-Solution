class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int layerSize = min(n/2, m/2);

        for(int layer = 0; layer < layerSize; layer++){
            vector<int> temp;
            int top = layer;
            int bottom = m-layer-1;
            int left = layer;
            int right = n-layer-1;

            for(int j = left; j <= right; j++){
                temp.push_back(grid[top][j]);
            }

            for(int i = top+1; i <= bottom; i++){
                temp.push_back(grid[i][right]);
            }

            for(int j = right-1; j >= left; j--){
                temp.push_back(grid[bottom][j]);
            }

            for(int i = bottom-1; i > top; i--){
                temp.push_back(grid[i][left]);
            }

            int normalized_k = k % temp.size();
            int idx = 0;

            rotate(temp.begin(), temp.begin()+normalized_k, temp.end());

            for(int j = left; j <= right; j++){
                grid[top][j] = temp[idx++];
            }

            for(int i = top+1; i <= bottom; i++){
                grid[i][right] = temp[idx++];
            }

            for(int j = right -1; j >= left; j--){
                grid[bottom][j] = temp[idx++];
            }

            for(int i = bottom - 1; i > top; i--){
                grid[i][left] = temp[idx++];
            }
        }

        return grid;
    }
};