class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long,int> mp;

        for(int &x : nums){
            mp[x]++;
        }
        int result = 0;

        if(mp[1]%2){
            result = mp[1];
        }else{
            result = mp[1] - 1;
        }

        for(auto &[num,_] : mp){
            if(num == 1) continue;

            long long cur = num;
            int len = 0;

            while(mp.count(cur) && mp[cur] > 1){
                len += 2;
                cur = cur*cur;
            }

            if(mp.count(cur) == 1){
                len += 1;
            }else{
                len -= 1;
            }

            result = max(result, len);
        }

        return result;
    }
};