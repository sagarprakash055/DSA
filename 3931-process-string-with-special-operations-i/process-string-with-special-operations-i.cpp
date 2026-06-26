class Solution {
public:
    string processStr(string s) {
        int n = s.size();
        string result = "";
        for(int i = 0; i < n; i++){
            if(s.at(i) >= 'a' && s.at(i) <= 'z'){
                result += s.at(i);
            }
            else if(s.at(i) == '#'){
                result += result;
            }
            else if(s.at(i) == '%'){
                reverse(result.begin(), result.end());
            }
            else{
                if(!result.empty()){
                    result.pop_back();
                }
            }
        }
        return result;
    }
};