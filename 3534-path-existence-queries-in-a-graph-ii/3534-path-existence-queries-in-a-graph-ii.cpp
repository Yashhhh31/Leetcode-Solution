class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>>A(n);
        for(int i=0;i<n;i++){
            A[i]={nums[i],i};
        }
        sort(A.begin(),A.end());
        vector<int> pos(n);
        for(int i=0;i<n;++i){
            pos[A[i].second]=i;
        }
        int LOG=20;
        vector<vector<int>> up(n,vector<int>(LOG));
        for(int i=0, j=0;i<n;++i){
            while(j<n && A[j].first-A[i].first<=maxDiff){
                j++;
            }
            up[i][0]=j-1;
        }
        for(int k=1;k<LOG;++k){
            for(int i=0;i<n;++i){
                up[i][k]=up[up[i][k-1]][k-1];
            }
        }
        vector<int>ans;
        ans.reserve(queries.size());

        for(const auto& q : queries){
            int x=pos[q[0]];
            int y=pos[q[1]];
            if(x>y) swap(x,y);
            if(x==y){
                ans.push_back(0);
                continue;
            }
            if(up[x][LOG-1]<y){
                ans.push_back(-1);
                continue;
            }
            int dist=0;
            int curr=x;
            for (int k = LOG - 1; k >= 0; --k) {
                if (up[curr][k] < y) {
                    curr = up[curr][k];
                    dist += (1 << k);
                }
            }
            ans.push_back(dist+1);

        }
        return ans;
        
    }

};