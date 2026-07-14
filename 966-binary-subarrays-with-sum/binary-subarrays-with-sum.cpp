class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal-1);
    }
    int atmost(vector<int>& nums, int goal){
        int n = nums.size();
        int l = 0, r = 0;
        if(goal < 0) return 0;
        int sum = 0, count = 0;
        while(r < n){
            sum += nums[r];
            while(sum > goal){
                sum = sum - nums[l];
                l++;
            }
            count = count + (r-l+1);
            r++;
        }
        return count;

    }
};