class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        int maxi = nums[0];
        // vector<int> gcds;

        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);

            nums[i] = __gcd(nums[i], maxi);
        }

        long long sum = 0;
        int l = 0;
        int r = n-1;

        sort(begin(nums), end(nums));

        while(l < r){
            sum += __gcd(nums[l++],nums[r--]);
        }

        return sum;
    }
};