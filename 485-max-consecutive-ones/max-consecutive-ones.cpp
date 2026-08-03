class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int count = 0;
        int maxfreq = 0;
        while(r < n){
            if(nums[r] == 1){
                count++;
                maxfreq = max(maxfreq, count);
            }else{
                count = 0;
            }
            r++;
        }
        return maxfreq;;
    }
};