class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        int sign = 1;
        long long ans = 0;

        while(i < n && s[i] == ' '){
            i++;
        }

        if(i < n && (s[i] == '-' || s[i] == '+')){
            sign = (s[i] == '-') ? -1:1;
            i++;
        }

        while(i < n && s[i] >= '0' && s[i] <= '9'){
            int digit = s[i] - '0';
            ans = ans*10 + digit;
            if (sign == 1 && ans >= INT_MAX) return INT_MAX;
            if (sign == -1 && -ans <= INT_MIN) return INT_MIN;
            i++;
        }
        return (int) (ans*sign);
    }
};