class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result(n);

        int lower = 0;
        int equal = 0;

        for(int i=0; i<n; i++){
            if(nums[i] < pivot){
                lower++;
            }else if(nums[i] == pivot){
                equal++;
            }
        }

        int l = 0;
        int m = lower;
        int r = lower+equal;

        for(int &x : nums){
            if(x < pivot){
                result[l++] = x;
            }else if(x == pivot){
                result[m++] = x;
            }else{
                result[r++] = x;
            }
        }

        return result;
    }
};