class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int sum = 0;
        int mini = INT_MAX;

        while (r < n) {
            sum += nums[r];

            while (sum >= target) {
                int len = r - l + 1;
                mini = min(mini, len);

                sum -= nums[l];
                l++;
            }

            r++;
        }

        if (mini == INT_MAX) {
            return 0;
        }

        return mini;
    }
};