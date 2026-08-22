class Solution {
public:

    int dfs(unordered_map<int,vector<int>>& adj, int u, int parent, vector<bool>& hasApple){

        int time = 0;

        for(int& child : adj[u]){
            if(child == parent)
                continue;
            
            int childTime = dfs(adj, child, u, hasApple);

            if(childTime > 0 || hasApple[child]){
                time += childTime + 2;
            }
        }

        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        unordered_map<int,vector<int>> adj;

        for(auto& x : edges){
            int u = x[0];
            int v = x[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(adj, 0, -1, hasApple);
    }
};