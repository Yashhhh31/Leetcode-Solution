class Solution {
public:

    char dfs(unordered_map<char,vector<char>>& adj, char cur, vector<int>& visited){
        char smallest = cur;
        visited[cur - 'a'] = true;

        for(char& child : adj[cur]){

            if(visited[child - 'a']) continue;

            smallest = min(smallest, dfs(adj, child, visited));
        }

        return smallest;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        int n = s1.length();

        unordered_map<char,vector<char>> adj;

        for(int i=0; i<n; i++){
            int u = s1[i];
            int v = s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string result = "";

        for(char& ch : baseStr){
            vector<int> visited(26,false);

            result += dfs(adj, ch, visited);
        }

        return result;

    }
};