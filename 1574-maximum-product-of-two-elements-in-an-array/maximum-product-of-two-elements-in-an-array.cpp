class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = n-1;
        int j = n-2;
        int ans = (nums[i]-1) * (nums[j]-1);
        return ans;
        
    }
};