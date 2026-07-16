class Solution {
public:

    typedef pair<int, pair<int,int>> P;
    vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,-1}, {0,1}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        pq.push({0, {0,0}});
        result[0][0] = 0;

        auto isSafe = [&](int x , int y){
            return (x >= 0 && x < m && y >= 0 && y < n);
        };

        while(!pq.empty()){
            int diff = pq.top().first;
            auto coord = pq.top().second;
            pq.pop();

            int x = coord.first;
            int y = coord.second;

            for(auto& dir : dirs){
                int x_ = x + dir.first;
                int y_ = y + dir.second;

                if(isSafe(x_, y_)) {

                    int absDiff = abs(heights[x][y] - heights[x_][y_]);
                    int maxDiff = max(diff, absDiff);
                    
                    if(maxDiff < result[x_][y_]){
                        result[x_][y_] = maxDiff;
                        pq.push({maxDiff, {x_,y_}});
                    }
                    
                }
            }

        }

        return result[m-1][n-1];

    }
};