class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0; 
        int r = n-1;
        int maximum = 0;
        while(l < r){
            maximum = max((nums[l]+nums[r]), maximum);
            l++;
            r--;
        }
        return maximum;
    }
};