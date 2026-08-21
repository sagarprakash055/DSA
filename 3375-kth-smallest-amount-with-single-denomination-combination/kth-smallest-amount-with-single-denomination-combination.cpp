class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
       
        long long left = 1;
        long long right = (long long)*min_element(coins.begin(), coins.end()) * k;
        long long ans = right;

        auto countMultiples = [&](long long target) {
            long long total = 0;
            
           
            for (int mask = 1; mask < (1 << n); ++mask) {
                long long current_lcm = 1;
                int set_bits = 0; 
                
                for (int i = 0; i < n; ++i) {
                    if (mask & (1 << i)) {
                        set_bits++;
                        long long gcd_val = std::gcd(current_lcm, (long long)coins[i]);

                        if ((current_lcm / gcd_val) > target / coins[i]) {
                            current_lcm = target + 1; 
                            break;
                        }
                        
                        current_lcm = (current_lcm / gcd_val) * coins[i];
                    }
                }
                if (set_bits % 2 == 1) {
                    total += target / current_lcm;
                } else {
                    total -= target / current_lcm;
                }
            }
            return total;
        };

        // 3. Binary Search

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            
            if (countMultiples(mid) >= k) {
                ans = mid;         
                right = mid - 1; 
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};