class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq(26,0);
        for(char c : s){
            freq[c-'a']++;
        }
        string left = "";
        string middle = "";
        for(int i = 0; i < 26; i++){
            if(freq[i]  >0){
            if(freq[i]%2 != 0){
                middle += (char)(i+'a');
            }
            left.append(freq[i]/2, i+'a');
            }
        }
        string right = left;
        reverse(right.begin(), right.end());
        return left+middle+right;
    }
};