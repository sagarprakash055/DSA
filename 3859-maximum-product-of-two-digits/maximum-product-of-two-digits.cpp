class Solution {
public:
    int maxProduct(int n) {
        int maxdig = 0;
        int secmax = 0;
        while(n > 0){
            int digit = n%10;

            if(digit > maxdig){
                secmax = maxdig;
                maxdig = digit;
            }
            else if(digit > secmax){
                secmax = digit;
            }
            
            n = n/10;
        }
        return maxdig*secmax;
    }
};