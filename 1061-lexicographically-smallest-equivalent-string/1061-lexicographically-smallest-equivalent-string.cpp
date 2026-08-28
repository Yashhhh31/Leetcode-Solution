class Solution {
public:
    vector<int> parent;

    int find(int x){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b){
        a = find(a);
        b = find(b);

        if(a == b)
            return;
        
        if(a < b){
            parent[b] = a;
        }else{
            parent[a] = b;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        parent.resize(26);

        for(int i=0; i<26; i++){
            parent[i] = i;
        }

        for(int i=0; i<n; i++){
            int a = s1[i] - 'a';
            int b = s2[i] - 'a';

            unite(a,b);
        }

        string result = "";

        for(char& ch : baseStr){
            result += char(find(ch - 'a') + 'a');
        }

        return result;

    }
};