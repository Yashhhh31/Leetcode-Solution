class Solution {
public:
    vector<vector<int>> result;

    void dfs(int u, vector<vector<int>>& graph, int tar, vector<int>& temp){
        temp.push_back(u);

        if(u == tar){
            result.push_back(temp);
        }else{

            for(int& v : graph[u]){
                dfs(v, graph, tar, temp);
            }
        }

        temp.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size();

        vector<int> temp;

        dfs(0,graph,n-1, temp);

        return result;

    }
};