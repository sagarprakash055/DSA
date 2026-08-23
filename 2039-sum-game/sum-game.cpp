class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int sumL = 0, sumR = 0;
        int qL = 0, qR = 0;

        // Count sums and '?' for the left half
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') qL++;
            else sumL += num[i] - '0';
        }
        
        // Count sums and '?' for the right half
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') qR++;
            else sumR += num[i] - '0';
        }

        // Alice wins if the total number of '?' is odd
        if ((qL + qR) % 2 != 0) {
            return true; 
        }

        // If even, Alice wins ONLY IF Bob cannot perfectly balance the board
        return 2 * (sumL - sumR) != 9 * (qR - qL);
    }
};