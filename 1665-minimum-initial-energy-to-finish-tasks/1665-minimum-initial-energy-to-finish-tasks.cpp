class Solution {
public:

    int n;

    bool isPossible(vector<vector<int>>& tasks, int energy){
        
        for(vector<int> &v : tasks){
            int mini = v[1];
            int reduceEnergy = v[0];

            if(mini > energy){
                return false;
            }

            energy -= reduceEnergy;
        }

        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        n = tasks.size();

        sort(tasks.begin(), tasks.end(),[](vector<int>&a, vector<int> &b){
            int diff1 = abs(a[0] - a[1]);
            int diff2 = abs(b[0] - b[1]);

            return diff1 > diff2;
        });

        int l = 0;
        int r = 1e9;
        int result;

        while(l <= r){
            int mid = l+(r-l)/2;

            if(isPossible(tasks,mid)){
                result = mid;
                r = mid - 1;
            }else{
                l = mid+1;
            }
        }

        return result;
    }
};