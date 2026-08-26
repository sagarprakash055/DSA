class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set <int> freq;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            freq.insert(nums[i]);
        }

        int mul = 1;
        while(true){
            int current_mul = k*mul;

            if(!freq.count(current_mul)){
                return current_mul;
            }
            mul++;
        }
    }
};