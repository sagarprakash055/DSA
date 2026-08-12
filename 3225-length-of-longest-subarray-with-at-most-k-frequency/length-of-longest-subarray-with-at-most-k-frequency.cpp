class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
      int n = nums.size();
        int l = 0, r = 0;
        unordered_map<int, int> freq;
      
        int maxLength = 0; 

        while(r < n) {
            freq[nums[r]]++;
    
            while (freq[nums[r]] > k) {
                freq[nums[l]]--; 
                l++;             
            }
            maxLength = max(maxLength, r - l + 1);
            r++;
        }
        
        return maxLength;
    }
};