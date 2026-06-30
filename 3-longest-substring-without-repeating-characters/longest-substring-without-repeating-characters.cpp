class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxleng = 0;
        for(int i = 0; i < n; i++){
            unordered_map <int,int> mp;
            for(int j = i; j < n; j++){
                if(mp[s[j]] == 1){
                    break;
                }else{
                    int length = j-i+1;
                    maxleng = max(maxleng, length);
                    mp[s[j]] = 1;
                }

            }
        }
        return maxleng;
    }
};