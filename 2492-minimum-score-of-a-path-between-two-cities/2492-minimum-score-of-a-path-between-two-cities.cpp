class Solution {
public:

    void dfs(int u, unordered_map<int,vector<pair<int,int>>>& adj, vector<bool> &visited, int &result){
        visited[u] = true;

        for(auto &p : adj[u]){
            int v = p.first;
            int d = p.second;

            result = min(result,d);

            if(!visited[v]){
                dfs(v, adj, visited, result);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {

        unordered_map<int,vector<pair<int,int>>> adj;

        for(vector<int> &vac : roads){
            int u = vac[0];
            int v = vac[1];
            int dist = vac[2];

            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }

        vector<bool> visited (n,false);

        int result = INT_MAX;

        dfs(1, adj, visited, result);

        return result;
    }
};