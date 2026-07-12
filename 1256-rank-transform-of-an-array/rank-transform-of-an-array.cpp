class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> sortedarr = arr;
        sort(sortedarr.begin(), sortedarr.end());

        unordered_map<int, int> mp;
        int rank = 1;
        for(int nums : sortedarr){
            if(mp.find(nums) == mp.end()){
                mp[nums] = rank;
                rank++;
            }
        }
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = mp[arr[i]];
        }
        return ans;

    }
};