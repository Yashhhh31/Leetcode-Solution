class Solution {
public:

    vector<vector<int>> dp;

    int solve(int l, int r, vector<int>& cumSum){

        if(l >= r){
            return 0;
        }

        if(dp[l][r] != -1){
            return dp[l][r];
        }

        int score = 0;

        for(int mid = l; mid < r; mid++){
            
            int leftSum = cumSum[mid] - (l-1 >= 0 ? cumSum[l-1] : 0);
            int rightSum = cumSum[r] - cumSum[mid];

            if(leftSum < rightSum){
                score = max(score, leftSum + solve(l, mid, cumSum));
            }else if(leftSum > rightSum){
                score = max(score, rightSum + solve(mid+1, r, cumSum));
            }else{
                score = max({score, leftSum + solve(l, mid, cumSum), rightSum + solve(mid+1 , r, cumSum)});
            }
        }

        return dp[l][r] = score;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> cumSum(n,0);
        cumSum[0] = stoneValue[0];

        dp.assign(501, vector<int>(501, -1));

        for(int i=1; i<n; i++){
            cumSum[i] = cumSum[i-1] + stoneValue[i];
        }

        return solve(0, n-1, cumSum);
    }
};