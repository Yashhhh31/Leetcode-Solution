class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n =nums.size();

        sort(nums.begin(), nums.end());

        vector<int> result;

        for(int i=1; i<n; i++){
            if(nums[i-1] != nums[i]-1){
                int cnt = abs(nums[i-1] - nums[i]) - 1;
                int inc = 1;
                while(cnt--){
                    result.push_back(nums[i-1] + inc);
                    inc++;
                }
            }
        }

        return result;
    }
};