class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n1 = players.size();
        int n2 = trainers.size();
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        long long count = 0;
        int l = 0, r = 0;
        while(l < n1 && r < n2){
            if(players[l] <= trainers[r]){
                count++;
                l++;
                r++;
            }else{
                r++;
            }
        }
        return count;
    }
};