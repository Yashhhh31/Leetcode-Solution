class Solution {
public:
    int n,m;

    int check(int a, vector<int>& potions, long long success){
        int l = 0;
        int r = m-1;

        while(l < r){
            int mid = l + (r-l)/2;

            long long mul = 1LL * potions[mid]*a;

            if(mul < success){
                l = mid +1;
            }else{
                r = mid;
            }
        }

        if(1LL * potions[l]* a < success){
            return 0;
        }

        return m-l;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        n = spells.size();
        m = potions.size();
        vector<int> result;

        sort(potions.begin(), potions.end());

        for(int i=0; i<n; i++){
            result.push_back(check(spells[i],potions,success));
        }

        return result;
    }
};