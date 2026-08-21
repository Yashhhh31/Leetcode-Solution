class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int m = maze.size();
        int n = maze[0].size();

        vector<vector<int>> direction = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        queue<pair<int,int>> que;
        que.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int cnt = 0;

        while(!que.empty()){
            int size = que.size();

            while(size--){
                int r = que.front().first;
                int c = que.front().second;
                que.pop();

                if(!(entrance[0] == r && entrance[1] == c) &&
                 (r == 0 || c == 0 || r == m-1 || c == n-1)){
                    return cnt;
                }

                for(auto& dir : direction){
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && maze[nr][nc] != '+'){
                        que.push({nr,nc});
                        maze[nr][nc] = '+';
                    }
                }

            }
            
            cnt++;
        }


        return -1;

    }
};