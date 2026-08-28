class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        int odds = 0;
        char mid_char = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 == 1) {
                odds++;
                mid_char = i + 'a';
            }
        }
        
        // Check if string can form a valid palindrome
        if (odds > 1) return "";
        if (n % 2 == 0 && odds != 0) return "";
        if (n % 2 == 1 && odds != 1) return "";
        
        // Frequencies available for the first half
        vector<int> half_avail(26, 0);
        for (int i = 0; i < 26; i++) {
            half_avail[i] = count[i] / 2;
        }
        
        int H_len = n / 2;
        
        // Step 1: Check if the first half can exactly match target's first half
        string target_H = target.substr(0, H_len);
        bool can_form_target_H = true;
        vector<int> rem = half_avail;
        for (char c : target_H) {
            rem[c - 'a']--;
            if (rem[c - 'a'] < 0) {
                can_form_target_H = false;
                break;
            }
        }
        
        if (can_form_target_H) {
            string P_exact = target_H;
            if (n % 2 == 1) P_exact += mid_char;
            string rev_H = target_H;
            reverse(rev_H.begin(), rev_H.end());
            P_exact += rev_H;
            
            // If the exact first-half match already produces a strictly greater palindrome, return it.
            if (P_exact > target) {
                return P_exact;
            }
        }
        
        // Step 2: Find the deepest divergence point i in the first half to make it > target
        for (int i = H_len - 1; i >= 0; i--) {
            rem = half_avail;
            bool possible = true;
            
            // Check if we can fulfill the prefix up to i-1
            for (int j = 0; j < i; j++) {
                int c = target[j] - 'a';
                rem[c]--;
                if (rem[c] < 0) {
                    possible = false;
                    break;
                }
            }
            
            if (!possible) continue;
            
            // Find the smallest valid character strictly greater than target[i]
            int target_char = target[i] - 'a';
            int best_c = -1;
            for (int c = target_char + 1; c < 26; c++) {
                if (rem[c] > 0) {
                    best_c = c;
                    break;
                }
            }
            
            if (best_c != -1) {
                string H = target.substr(0, i);
                H += (char)(best_c + 'a');
                rem[best_c]--;
                
                // Append remaining available characters in lexicographical (sorted) order
                for (int c = 0; c < 26; c++) {
                    while (rem[c] > 0) {
                        H += (char)(c + 'a');
                        rem[c]--;
                    }
                }
                
                // Construct and return the full palindrome
                string P = H;
                if (n % 2 == 1) P += mid_char;
                string rev_H = H;
                reverse(rev_H.begin(), rev_H.end());
                P += rev_H;
                
                return P;
            }
        }
        
        return "";
    }
};