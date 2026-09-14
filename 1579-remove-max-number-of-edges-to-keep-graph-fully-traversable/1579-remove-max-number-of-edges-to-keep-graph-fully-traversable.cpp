class DSU {
public : 
    vector<int> parent;
    vector<int> rank;
    int component;

    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,1);
        component = n;

        for(int i=1; i<=n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int a, int b){
        int a_parent = find(a);
        int b_parent = find(b);

        if(a_parent == b_parent){
            return;
        }

        if(rank[a_parent] > rank[b_parent]){
            parent[b_parent] = a_parent;
        }else if(rank[a_parent] < rank[b_parent]){
            parent[a_parent] = b_parent;
        }else{
            parent[a_parent] = b_parent;
            rank[b_parent]++;
        }

        component--;
    }

    bool isSingleComponent(){
        return component == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        DSU Alice(n);
        DSU Bob(n);

        auto lambda = [](const vector<int>& a, const vector<int>& b){
            return a[0] > b[0];
        };

        sort(edges.begin(), edges.end(), lambda);

        int edgeCount = 0;

        for(auto& edge : edges){
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];

            if(type == 3){

                bool addEdgeKaraYaNhi = false;

                if(Alice.find(u) != Alice.find(v)){
                    Alice.Union(u,v);
                    addEdgeKaraYaNhi = true;

                }

                if(Bob.find(u) != Bob.find(v)){
                    Bob.Union(u,v);
                    addEdgeKaraYaNhi = true;
                }

                if(addEdgeKaraYaNhi){
                    edgeCount++;
                }

            } else if (type == 2){

                if(Bob.find(u) != Bob.find(v)){
                    Bob.Union(u,v);
                    edgeCount++;
                }

            } else {

                if(Alice.find(u) != Alice.find(v)){
                    Alice.Union(u,v);
                    edgeCount++;

                }

            }
        }

        if(Alice.isSingleComponent() && Bob.isSingleComponent()){
            return edges.size() - edgeCount;
        }

        return -1;

    }
};