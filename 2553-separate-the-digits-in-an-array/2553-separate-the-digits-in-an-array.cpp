class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        for(int &num : nums){
            vector<int> digit;

            while(num > 0){
                digit.push_back(num%10);
                num /= 10;
            }

            for(int i=digit.size()-1; i>=0; i--){
                result.push_back(digit[i]);
            }
        }

        return result;
    }
};