class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int left = 0;
        int right = n - 1;
        int idx = n - 1;

        while(left <= right) {

            int lsq = nums[left] * nums[left];
            int rsq = nums[right] * nums[right];

            if(lsq > rsq) {
                ans[idx--] = lsq;
                left++;
            }
            else {
                ans[idx--] = rsq;
                right--;
            }
        }

        return ans;
    }
};