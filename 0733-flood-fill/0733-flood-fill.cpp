class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int m = image.size();
        int n = image[0].size();
        
        queue<pair<int,int>> que;
        que.push({sr,sc});
        int original = image[sr][sc];

        if(original == color){
            return image;
        }
        
        image[sr][sc] = color;

        vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!que.empty()){
            auto p = que.front();
            que.pop();

            for(auto& dir : direction){
                int nr = dir[0] + p.first;
                int nc = dir[1] + p.second;

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && original == image[nr][nc]){
  
                    que.push({nr,nc});
                    image[nr][nc] = color;

                }
            }
        }

        return image;

    }
};