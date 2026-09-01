class Solution {
public:

    int cnt = 0;

    void dfs(unordered_map<int, vector<pair<int,int>>>& adj, int u, int parent){

        for(auto& node : adj[u]){
            int v = node.first;
            int flag = node.second;

            if(v == parent){
                continue;
            }

            if(flag == 1){
                cnt++;
            }

            dfs(adj, v, u);
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        
        unordered_map<int, vector<pair<int,int>>> adj;

        for(auto& c : connections){
            int u = c[0];
            int v = c[1];

            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }

        dfs(adj, 0, -1);

        return cnt;

    }
};