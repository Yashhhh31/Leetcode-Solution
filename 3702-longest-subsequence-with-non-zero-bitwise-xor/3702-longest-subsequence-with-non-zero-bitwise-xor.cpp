class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        int n = nums.size();
        int xorr = 0;
        bool isZero = true;

        for(int x : nums){
            xorr ^= x;

            if(x != 0){
                isZero = false;
            }
        }

        if(xorr != 0){
            return n;
        }

        if(!isZero)
            return n-1;

        return 0;

    }
};