class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cookies = 0;
        int child = 0;
        while(cookies < s.size() && child < g.size()){
            if(s[cookies] >= g[child]){
                child++;
            }
            cookies++;
        }
       return child;
    }
};