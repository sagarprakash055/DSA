class Solution {
public:
    int lengthOfLastWord(string s) {
       int length = 0;
        int n = s.size();
        
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] != ' ') {
                length++;
            } else if (length > 0) {
                break;
            }
        }
        
        return length;
        }
};