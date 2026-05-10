class Solution {
public:
    int n;
    vector<int>dp;

    int solve(vector<int>& nums, int i, int target){
       
        if(i == n-1){
            return dp[i] = 0;
        }

        if(dp[i] != -2) return dp[i];

        int result = INT_MIN;
        for(int j = i+1; j < n; j++){
            if(abs(nums[i] - nums[j]) <= target){
                int temp = 1 + solve(nums,j,target);
                result = max(result,temp);
            }
        }

        return dp[i] = result;
    }
    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        dp.assign(n , -2);

        int result = solve(nums,0,target);
        return result < 0 ? -1 : result;
    }
};