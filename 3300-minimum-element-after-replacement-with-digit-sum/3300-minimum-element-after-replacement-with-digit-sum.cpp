class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;

        for(int i=0; i<n; i++){
            int sum = 0;
            int num = nums[i];

            while(num > 0){
                int digit = num%10;
                sum += digit;
                num /= 10;
            }

            mini = min(mini,sum);
        }

        return mini;
    }
};