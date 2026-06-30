class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count[3] = {0};
        int ans = 0;
        int l = 0, r = 0;
        while (r < n) {
            count[s[r] - 'a']++;
            while(count[0] > 0 && count[1] > 0 && count[2] > 0) {
                ans += n - r;
                count[s[l] - 'a']--;
                l++;
            }
            r++;
        }
        return ans;
    }
};