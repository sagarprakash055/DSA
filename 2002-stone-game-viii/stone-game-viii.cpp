class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
       int n = stones.size();
       int current_prefix_sum = 0;
       for(int stone : stones){
        current_prefix_sum += stone;
       }
       int dp = current_prefix_sum;
       for(int i = n-2; i >= 1; i--){
        current_prefix_sum -= stones[i+1];
        dp = max(current_prefix_sum - dp, dp);
       }
       return dp;
    }
};