class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        for(int i=0; i<n; i++){
            int target = nums1[i];

            int start = 0;
            int end = m-1;
            
            while(start <= end){
                int mid = start + (end - start)/2;

                if(nums2[mid] == target){
                    return target;
                }

                if(nums2[mid] > target){
                    end = mid-1;
                }else{
                    start = mid+1;
                }
            }
        }

        return -1;
    }
};