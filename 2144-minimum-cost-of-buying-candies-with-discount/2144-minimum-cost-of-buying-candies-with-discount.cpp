class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();

        sort(begin(cost), end(cost), greater<int> ());

        int sum = 0;
        int i = 0;

        while(i < n){
            sum += cost[i++];
           if(i < n) sum += cost[i++];

            i++;
        }

        return sum;
    }
};