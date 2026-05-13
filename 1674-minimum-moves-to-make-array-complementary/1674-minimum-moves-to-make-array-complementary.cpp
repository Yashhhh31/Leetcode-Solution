class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int complementaryMaxSum= 2*limit+2;// just added +2 in case of array bounds
        vector<int> sweepLine(complementaryMaxSum,0);// complementary sum range : [2,2*limit];
        vector<int> pairMapSum(complementaryMaxSum,0);
        int n=nums.size();
        for(int i=0,j=n-1;i<j;)
        {
            pairMapSum[nums[i]+nums[j]]++;
            int mnPossible=1+min(nums[i],nums[j]);
            int mxPossible= max(nums[i],nums[j])+limit;
            sweepLine[mnPossible]++;
            sweepLine[mxPossible+1]--;
            i++;
            j--;
        }
        for(int i=1;i<complementaryMaxSum;i++) sweepLine[i]+=sweepLine[i-1];

        // Linear search on all possible complementary sums : [2,2*limit+2];
        int ans=INT_MAX;
        for(int i=2;i<complementaryMaxSum;i++)
        {
            // No of sweepLine segments that intersect at i. (conceptually it is no of pairs that can have i as their sum with atMax 1 move)
            int part1=sweepLine[i];

            // No of sweepLine segments that dont intersect at i.(2Moves)
            int part2=(n/2-part1)*2;// n-2*part1
           
            // no need of moves pairs (o moves)
            int part3=pairMapSum[i];

            ans=min(ans,part1+part2-part3);
        }
        return ans;

    }
};
