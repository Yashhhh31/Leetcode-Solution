class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int x){
        
        if(parent[x] == x){
            return x;
        }

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

        parent.resize(n);
        rank.resize(n);

        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        int component = n;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isSimilar(strs[i], strs[j]) && find(i) != find(j)){
                    Union(i,j);
                    component--;
                }
            }
        }

        return component;
    }
};