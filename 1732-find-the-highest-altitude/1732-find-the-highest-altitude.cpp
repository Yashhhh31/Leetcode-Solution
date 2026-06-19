class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();

        int maxi = INT_MIN;
        int sum = 0;

        for(int &x : gain){
            sum += x;
            maxi = max(maxi,sum);
        }

        return maxi < 0 ? 0 : maxi;
    }
};