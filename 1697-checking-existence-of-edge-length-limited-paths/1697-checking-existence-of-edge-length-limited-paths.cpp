class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int x){

        if(x == parent[x]){
            return x;
        }

        return parent[x] = find(parent[x]);

    }

    void Union(int a, int b){
        int parent_a = find(a);
        int parent_b = find(b);

        if(parent_a == parent_b){
            return;
        }

        if(rank[parent_a] > rank[parent_b]){
            parent[parent_b] = parent_a;
        }else if(rank[parent_a] < rank[parent_b]){
            parent[parent_a] = parent_b;
        }else{
            parent[parent_a] = parent_b;
            rank[parent_b]++;
        }
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        parent.resize(n);
        rank.resize(n);

        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        for(int i=0; i<queries.size(); i++){
            queries[i].push_back(i);
        }

        auto lambda = [&](auto &v1, auto &v2){
            return v1[2] < v2[2];
        };

        sort(begin(queries), end(queries), lambda);
        sort(begin(edgeList), end(edgeList), lambda);

        int j = 0;
        vector<bool> result(queries.size());

        for(int i=0; i<queries.size(); i++){
            vector<int> querie = queries[i];

            int u = querie[0];
            int v = querie[1];
            int t = querie[2];
            int idx = querie[3];

            while(j < edgeList.size() && edgeList[j][2] < t){
                Union(edgeList[j][0], edgeList[j][1]);
                j++;
            }

            if(find(u) == find(v)){
                result[idx] = true;
            }else{
                result[idx] = false;
            }
        }


        return result;
    }
};