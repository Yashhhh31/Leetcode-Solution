class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1;
        int maxi = 1;

        for(int i=1; i<n; i++){
            if(nums[i-1] < nums[i]){
                cnt++;
                maxi = max(maxi, cnt);
            }else{
                cnt = 1;
            }
        }

        return maxi; 
    }
};