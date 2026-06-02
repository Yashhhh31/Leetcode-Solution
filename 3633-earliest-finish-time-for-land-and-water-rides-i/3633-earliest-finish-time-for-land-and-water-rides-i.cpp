class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int land = INT_MAX, water = INT_MAX;
        int result = land;

        for(int i=0; i<n; i++){
            land = min(land, landStartTime[i] + landDuration[i]);
        }

        for(int i=0; i<m; i++){
            water = min(water, waterStartTime[i] + waterDuration[i]);
            result = min(result, max(land, waterStartTime[i]) + waterDuration[i]);
        }

        for(int i=0; i<n; i++){
            result = min(result, max(water, landStartTime[i]) + landDuration[i]);
        }

        return result;
    }
};