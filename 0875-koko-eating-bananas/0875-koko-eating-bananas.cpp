class Solution {
public:

    int n;
    bool check(int mid, vector<int>& piles, int h){
        int cnt = 0;

        for(int i=0; i<n; i++){
            int num = piles[i];

            cnt += num/mid;

            num = num % mid;

            if(num > 0){
                cnt += 1;
            }

            if(cnt > h){
                return false;
            }

        }

        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        n = piles.size();

        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = 0;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(check(mid,piles,h)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return ans;
    }
};