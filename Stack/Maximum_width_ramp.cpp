class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        for(int i = 0; i< n; i++){
            if(st.empty() || nums[st.top()] >= nums[i]){
                st.push(i);
            }
        }
        int width = INT_MIN;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                width = max(width, i - st.top());
                st.pop();
            }
        }
        return width;
    }
};