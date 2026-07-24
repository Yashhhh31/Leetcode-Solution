class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int n = nums.size();
        int gcdd = nums[0];

        for(int i=1; i<n; i++){
            gcdd = __gcd(gcdd,nums[i]);
        }

        return gcdd == 1;
    }
};