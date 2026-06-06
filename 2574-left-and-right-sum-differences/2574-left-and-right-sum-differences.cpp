class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);

        for(int i=1; i<n; i++){
            ans[i] = nums[i-1] + ans[i-1];
        }

        int right = 0;
        for(int i=n-2; i>=0; i--){
            right = right + nums[i+1];
            ans[i] = abs(ans[i] - right);
        }

        return ans;
    }
};