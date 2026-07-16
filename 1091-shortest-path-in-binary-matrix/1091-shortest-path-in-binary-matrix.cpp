class Solution {
public:

    typedef pair<int,int> P;
    vector<P> direction = {{1,0}, {0,1}, {0,-1}, {-1,0}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();

        if(grid[0][0] == 1) return -1;

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0,0});
        result[0][0] = 1;

        while(!pq.empty()){
            auto[r,c] = pq.top();
            pq.pop();

            for(auto& dir : direction){
                int new_r = r + dir.first;
                int new_c = c + dir.second;

                if(new_r < 0 || new_r >= m || new_c < 0 || new_c >= n || grid[new_r][new_c] == 1)
                     continue;

                if(result[r][c] + 1 < result[new_r][new_c]){
                    result[new_r][new_c] = result[r][c] + 1;

                    pq.push({new_r, new_c});
                }
            }
        }

        return result[m-1][n-1] >= INT_MAX ? -1 : result[m-1][n-1];
    }
};