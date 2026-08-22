class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int digit;
        int original = n;
        while(n > 0){
            digit = n%10;
            sum += digit;
            product = product * digit;
            n = n/10;   
        }
        int  ans = sum + product;
        cout<<ans;
        if(original % ans == 0){
            return true;
        }else{
            return false;
        }
    }
};