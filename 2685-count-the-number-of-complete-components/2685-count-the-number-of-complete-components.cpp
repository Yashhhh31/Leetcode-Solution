class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> mp;

        for(vector<int>& edge : edges){
            int u = edge[0];
            int v = edge[1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        vector<bool> vis(n,false);
        int count = 0;

        for(int i=0; i<n; i++){
            if(vis[i]) continue;

            queue<int> q;
            q.push(i);
            vis[i] = true;

            int nodes = 0;
            int degreeSum = 0;

            while(!q.empty()){

                int u = q.front();
                q.pop();

                nodes++;

                degreeSum += mp[u].size();

                for(int v : mp[u]){
                    if(!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }

            if(degreeSum == nodes*(nodes-1)){
                count++;
            }
        }

        return count;
    }
};