class Solution {
public:
    int romanToInt(string s) {
        int roman[128] = {0};
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
        int n = s.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
           if(i < n-1 && roman[s[i]] < roman[s[i+1]]){
            sum -= roman[s[i]];
           }else{
            sum += roman[s[i]];
           }
        }
        return sum;
    }
};