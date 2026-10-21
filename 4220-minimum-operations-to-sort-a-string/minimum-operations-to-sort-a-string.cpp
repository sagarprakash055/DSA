class Solution {
public:
    int minOperations(string s) {
         string t = s;
        sort(t.begin(), t.end());

        if (t == s) return 0;

        if (s.size() == 2) return -1;

        if (t.front() == s.front() || t.back() == s.back()) return 1;

        vector<int> freq(26);
        for (char c: s) {
            freq[c - 'a']++;
        }

        if (t.front() == s.back() && t.back() == s.front() && freq[t.front() - 'a'] == 1 && freq[t.back() - 'a'] == 1) return 3;
        
        return 2;
    }
};