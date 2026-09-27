class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 2) return nums;
        int duo = 0;

        for(int i=0; i<n; i++){
            duo = duo ^ nums[i];
        }

        int first_grp = 0;
        int second_grp = 0;
        int cnt = 0;

        while(((duo >> cnt)&1) != 1){
            cnt++;
        }

        for(int i=0; i<n; i++){
            if(((nums[i] >> cnt)&1) == 1){
                first_grp ^= nums[i];
            }else{
                second_grp ^= nums[i];
            }
        }

        return {first_grp,second_grp};
    }
};