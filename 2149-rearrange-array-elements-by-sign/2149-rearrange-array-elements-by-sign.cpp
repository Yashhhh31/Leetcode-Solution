class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        int positive = 0;
        int negative = 1;

        vector<int> result(n);

        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                result[positive] = nums[i];
                positive += 2;
            }else{
                result[negative] = nums[i];
                negative += 2;
            }
        }

        return result;
    }
};