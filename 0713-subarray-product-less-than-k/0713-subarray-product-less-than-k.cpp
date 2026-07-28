class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        if(k <= 1){
            return 0;
        }

        int i = 0;
        int j = 0;
        int cnt = 0;
        int pro = 1;
        int ans = 0;

        while(j < n){
            pro *= nums[j];
            cnt++;

            while(pro >= k){
                pro/= nums[i];
                i++;
                cnt--;
            }

            ans += cnt;

            j++;
        }

        return ans;
    }
};