class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int expected = nums[0];
        for(int i = 0; i < n; i++){
            if(nums[i] != expected){
                ans.push_back(expected);
                i--;
            }
            expected++;
        }
        return ans;
    }
};