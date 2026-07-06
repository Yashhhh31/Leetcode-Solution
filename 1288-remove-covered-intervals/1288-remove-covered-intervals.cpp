class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> result;

        auto lambda = [&](vector<int> &a,vector<int>&b){
            if(a[0] == b[0]){
                return a[1] > b[1];
            }

            return a[0] < b[0];
        };

        sort(intervals.begin(), intervals.end(),lambda);
        result.push_back(intervals[0]);

        for(vector<int>& v : intervals){
            int val = result.back()[1];
            if(val >= v[1]){
                continue;
            }

            result.push_back(v);
        }

        return result.size();
    }
};