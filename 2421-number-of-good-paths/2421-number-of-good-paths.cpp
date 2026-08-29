class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int x){

        if(x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int a, int b){

        int a_parent = find(a);
        int b_parent = find(b);

        if(a_parent == b_parent)
            return;

        if(rank[a_parent] > rank[b_parent]){
            parent[b_parent] = a_parent;
        }else if(rank[a_parent] < rank[b_parent]){
            parent[a_parent] = b_parent;
        }else{
            parent[a_parent] = b_parent;
            rank[b_parent]++;
        }

    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();

        parent.resize(n);
        rank.resize(n);

        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        unordered_map<int, vector<int>> adj;

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        map<int, vector<int>> val_to_node;

        for(int i=0; i<n; i++){
            val_to_node[vals[i]].push_back(i);
        }

        vector<bool> isActive(n, false);

        int result = n;

        for(auto& it : val_to_node){
            vector<int> nodes = it.second;

            for(int &u : nodes){
                for(auto& v : adj[u]){
                    if(isActive[v]){
                        Union(u,v);
                    }
                }

                isActive[u] = true;
            }

            vector<int> nodes_parent;

            for(int& u : nodes){
                nodes_parent.push_back(find(u));
            }

            sort(nodes_parent.begin(), nodes_parent.end());
            int sz = nodes_parent.size();

            for(int i=0; i<sz; i++){

                int curNode = nodes_parent[i];
                long long cnt = 0;

                while(i < sz && nodes_parent[i] == curNode){
                    cnt++;
                    i++;
                }

                i--;

                int formula = (cnt * (cnt - 1)/2);

                result += formula;
            }
        }

        return result;
    }
};