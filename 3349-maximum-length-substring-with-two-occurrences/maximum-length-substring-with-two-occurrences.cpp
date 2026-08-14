class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        vector<int>f(26);
        int l = 0; 
        int maxx = 0;
        for(int r = 0; r < n; r++){
            int c = s[r] - 'a';
            f[c]++;
            while(f[c] > 2){
                f[s[l] - 'a']--;
                l++;
            }
            maxx = max(maxx, r-l+1);
        }
        return maxx;
    }
};