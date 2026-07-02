class Solution {
public:
    int hammingWeight(int n) {
        vector<int>res;
        while(n > 0){
            res.push_back(n%2);
            n = n/2;
        }
        int r = res.size();
        int count = 0;
        for(int i = 0; i < r; i++){
            if(res[i] == 1){
                count++;
            }
        }
        return count;
    }
};