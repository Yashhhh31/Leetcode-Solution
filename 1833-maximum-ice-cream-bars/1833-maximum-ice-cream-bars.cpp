class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();

        sort(begin(costs), end(costs));
        int ans = 0;
        long long sum = 0;

        for(int i=0; i<n; i++){
            sum += costs[i];

            if(sum <= coins) ans++;
        }


        return ans;
    }
};