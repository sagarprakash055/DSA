class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        int max_i = 0;
        vector<int> current_count = count;
        
        // Find the longest prefix of `target` we can exactly form
        while (max_i < target.length() && max_i < s.length()) {
            if (current_count[target[max_i] - 'a'] > 0) {
                current_count[target[max_i] - 'a']--;
                max_i++;
            } else {
                break;
            }
        }
        
        // Greedily find the divergence point, starting from the longest possible matching prefix
        for (int i = max_i; i >= 0; --i) {
            
            if (i == target.length()) {
                // `s` has all characters of `target` and is longer. Just append remaining characters sorted.
                if (s.length() > target.length()) {
                    string res = target;
                    for (int k = 0; k < 26; ++k) {
                        res += string(current_count[k], k + 'a');
                    }
                    return res;
                }
            } else {
                // Find the smallest available character that is strictly greater than target[i]
                int chosen = -1;
                for (int k = target[i] - 'a' + 1; k < 26; ++k) {
                    if (current_count[k] > 0) {
                        chosen = k;
                        break;
                    }
                }
                
                // If found, append it and the remaining characters in ascending (sorted) order
                if (chosen != -1) {
                    string res = target.substr(0, i);
                    res += (char)(chosen + 'a');
                    current_count[chosen]--;
                    
                    for (int k = 0; k < 26; ++k) {
                        res += string(current_count[k], k + 'a');
                    }
                    return res;
                }
            }
            
            // Backtrack: put the (i-1)-th character back into our available pool
            if (i > 0) {
                current_count[target[i - 1] - 'a']++;
            }
        }
        
        return "";
    }
};