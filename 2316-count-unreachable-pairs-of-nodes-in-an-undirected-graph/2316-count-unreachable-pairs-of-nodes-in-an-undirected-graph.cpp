class Solution {
public:

    vector<bool> visited;

    void dfs(unordered_map<int,vector<int>> &adj, int u, long long &cnt){
        cnt++;
        visited[u] = true;

        for(int &v : adj[u]){
            if(!visited[v]){
                dfs(adj, v, cnt);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        
        unordered_map<int,vector<int>> adj;

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        visited.assign(n,false);

        long long countedNodes = 0;
        long long ans = 0;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                long long cnt = 0;
                dfs(adj, i, cnt);

                countedNodes += cnt;

                ans += cnt * (n - countedNodes);
            }
        }
        return ans;
    }
};