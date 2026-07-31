class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();

        if(n == 1){
            return nums[0] == k;
        }

        int cnt = 0;
        

        for(int i=0; i<n; i++){
            int gcd = nums[i];

            for(int j=i; j<n; j++){
                gcd = __gcd(gcd, nums[j]);
                if(gcd == k){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};