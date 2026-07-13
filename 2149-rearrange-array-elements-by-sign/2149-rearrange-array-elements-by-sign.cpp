class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int r = 0;

        vector<int> result;

        while(result.size() < n){
            while (nums[l] < 0) l++;
            result.push_back(nums[l++]);

            while (nums[r] > 0) r++;
            result.push_back(nums[r++]);
        }

        return result;
    }
};