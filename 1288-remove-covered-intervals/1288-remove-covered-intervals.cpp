class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        auto lambda = [&](vector<int> &a,vector<int>&b){
            if(a[0] == b[0]){
                return a[1] > b[1];
            }

            return a[0] < b[0];
        };

        sort(intervals.begin(), intervals.end(),lambda);
        int maxEnd = 0;
        int cnt = 0;

        for(vector<int>& v : intervals){
            if(v[1] > maxEnd){
                maxEnd = v[1];
                cnt++;
            }
        }

        return cnt;;
    }
};