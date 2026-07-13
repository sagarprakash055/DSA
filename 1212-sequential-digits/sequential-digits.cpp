class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digit = "123456789";
        vector<int> ans;
        int n = to_string(low).size();
        int m = to_string(high).size();
        for(int leng = n; leng <= m; leng++){
            for(int i = 0; i <= 9-leng; i++){
                string temp = digit.substr(i, leng);
                int num = stoi(temp);
                if(num >= low && num <= high){
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};