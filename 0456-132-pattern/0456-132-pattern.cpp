class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int nums2 = INT_MIN;
        int largest = 0;

        stack<int> st;

        for(int i=n-1; i>=0; i--){
            if(nums[i] < nums2){
                return true;
            }

            while(!st.empty() && nums[i] > st.top()){
                nums2 = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};