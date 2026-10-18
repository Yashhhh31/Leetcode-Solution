class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        int n = capacity.size();

        vector<int> required(n,0);

        for(int i=0; i<n; i++){
            required[i] = capacity[i] - rocks[i];
        }

        int cnt = 0;

        sort(required.begin(), required.end());

        for(int i=0; i<n; i++){
            if(additionalRocks >= required[i]){
                additionalRocks -= required[i];
                cnt++;
            }else{
                break;
            }
        }

        return cnt;

    }
};