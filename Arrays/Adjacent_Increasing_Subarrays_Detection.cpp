class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int some = k - 1;
        if(some == 0) return true;
        for(int j = k + 1; j < nums.size(); j++){
            if(nums[j] > nums[j - 1] && nums[j - k] > nums[j - k - 1]) some--;
            else some = k - 1;
            if(some == 0) return true;
        }
        return false;
    }
};