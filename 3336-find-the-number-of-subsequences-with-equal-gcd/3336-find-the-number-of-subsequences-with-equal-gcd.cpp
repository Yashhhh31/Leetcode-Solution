class Solution {
public:
    int n;
    int MOD = 1e9+7;
    // int dp[201][201][201];

    // int solve(vector<int>& nums, int i, int first, int second){

    //     if(i == n){
    //         if(first != 0 && second != 0){
    //             if(first == second){
    //                 return 1;
    //             }
    //         }

    //         return 0;
    //     }

    //     if(dp[i][first][second] != -1)
    //         return dp[i][first][second];


    //     int skip = solve(nums, i+1, first, second);
    //     int take1 = solve(nums, i+1, __gcd(first,nums[i]), second);
    //     int take2 = solve(nums, i+1, first,  __gcd(second,nums[i]));

    //     return dp[i][first][second] = (1LL * skip + take1 + take2 ) % MOD;
    // }

    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        int maxEl = *max_element(begin(nums), end(nums));

        vector<vector<int>>prev(maxEl+1,vector<int>(maxEl+1, 0));

        for(int first=0; first <= maxEl; first++){
            for(int second=0; second <= maxEl; second++){
                bool isNotZero = (first != 0 && second != 0);
                bool isEqual = (first == second);

                prev[first][second] = ( isNotZero && isEqual ) ? 1 : 0; 
            }
        }

        for(int i=n-1; i>=0; i--){
            vector<vector<int>>curr(maxEl+1,vector<int>(maxEl+1, 0));

            for(int first=0; first <= maxEl; first++){
                for(int second=0; second <= maxEl; second++){

                    int skip = prev[first][second];
                    int take1 = prev[__gcd(first,nums[i])][second];
                    int take2 = prev[first][__gcd(second,nums[i])];

                    curr[first][second] = ( 0LL + skip + take1 + take2 ) % MOD;

                }
            }

            prev = move(curr);
        }

        return prev[0][0];    
    }
};