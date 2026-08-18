class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if(k == n)
            return *max_element(begin(nums), end(nums));
        
        vector<int> freq(51, 0);

        for(int &x : nums){
            freq[x]++;
        }

        if(k == 1){
            for(int i=50; i>=0; i--){
                if(freq[i] == 1){
                    return i;
                }
            }

            return -1;
        }

        int result = -1;

        if(freq[nums[0]] == 1){
            result = max(result,nums[0]);
        }

        if(freq[nums[n-1]] == 1){
            result = max(result, nums[n-1]);
        }


        return result;

    }
};