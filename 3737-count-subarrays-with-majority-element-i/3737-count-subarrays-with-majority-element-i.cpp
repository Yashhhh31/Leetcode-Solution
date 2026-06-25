class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int,int> mp;

        long long validLeftPoints = 0;
        mp[0] = 1;

        long long result = 0;
        int cumSum = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == target){
                validLeftPoints += mp[cumSum];
                cumSum += 1;
            }else{
                cumSum -= 1;
                validLeftPoints -= mp[cumSum];
            }

            mp[cumSum] += 1;
            result += validLeftPoints;
        }


        return result;
    }
};