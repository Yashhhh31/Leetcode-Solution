class Solution {
public:
    typedef pair<int,int> P;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<P>> adj;

        for(vector<int>& x : times){
            int u = x[0];
            int v = x[1];
            int wt = x[2];

            adj[u].push_back({v,wt});
        }

        vector<int> result(n+1,INT_MAX);
        priority_queue<P,vector<P>, greater<P>> pq;

        pq.push({0,k});
        result[k] = 0;

        while(!pq.empty()){
            auto[d, node] = pq.top();
            pq.pop();

            if(d > result[node]) continue;

            for(auto& [v,wt] : adj[node]){
                if(d + wt < result[v]){
                    result[v] = d + wt;
                    pq.push({d+wt , v});
                }  
            }
        }

        int ans = 0;

        for(int i=1; i<=n; i++){
            ans = max(ans,result[i]);
        }

        return ans == INT_MAX ? -1 : ans;

    }
};