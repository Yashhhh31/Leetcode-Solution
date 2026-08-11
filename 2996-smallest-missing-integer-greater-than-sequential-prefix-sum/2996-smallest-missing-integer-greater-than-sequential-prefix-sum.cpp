class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());

        int missing = nums[0];
        if(n == 1){
            return nums[0] + 1;
        }

        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1] + 1){
                missing += nums[i];
            }else{
                while(st.count(missing)){
                    missing++;
                }

                break;
            }
        }

        return missing;
    }
};