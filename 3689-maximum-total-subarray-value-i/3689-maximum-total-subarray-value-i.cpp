class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mini = *min_element(nums.begin(), nums.end());
        long long max = *max_element(nums.begin(), nums.end());

        long long ans = 0;
        while(k--){
            ans += (max - mini);
        }

        return ans;
    }
};