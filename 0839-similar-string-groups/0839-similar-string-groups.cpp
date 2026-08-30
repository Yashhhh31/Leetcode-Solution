class Solution {
public:

    void dfs(unordered_map<int,vector<int>>& adj, int u, vector<bool>& visited){
        visited[u] = true;

        for(int& v : adj[u]){
            if(!visited[v]){
                dfs(adj, v, visited);
            }
        }
    }

    bool isSimilar(string s1, string s2){
        int m = s1.length();
        int cnt = 0;

        for(int i=0; i<m; i++){
            if(s1[i] != s2[i]){
                cnt++;
            }
        }

        return cnt == 2 || cnt == 0;
    }

    int numSimilarGroups(vector<string>& strs) {
        
        int n = strs.size();

        unordered_map<int,vector<int>> adj;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isSimilar(strs[i],strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int d = 0;
        vector<bool> visited(n,false);

        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(adj, i, visited);
                d++;
            }
        }

        return d;
    }
};