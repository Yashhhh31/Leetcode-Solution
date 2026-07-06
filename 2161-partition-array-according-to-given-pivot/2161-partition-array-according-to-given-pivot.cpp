class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        int l = 0;
        int r = n-1;

        int i=0;
        int j=n-1;

        vector<int> result(n);

        while(l < n){
            if(nums[l] < pivot){
                result[i] = nums[l];
                i++;
            }

            if(nums[r] > pivot){
                result[j] = nums[r];
                j--;
            }

            l++;
            r--;

        }

        while(i <= j){
            result[i] = pivot;
            i++;
        }

        return result;
    }
};