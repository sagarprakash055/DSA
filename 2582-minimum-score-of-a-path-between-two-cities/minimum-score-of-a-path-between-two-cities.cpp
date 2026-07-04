class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int dist = road[2];
            graph[u].push_back({v, dist});
            graph[v].push_back({u, dist});
        }
        
        queue<int> q;
        vector<bool> visited(n + 1, false);
        
        q.push(1);
        visited[1] = true;
        
        int min_score = 1e9;
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            for (const auto& edge : graph[current]) {
                int neighbor = edge.first;
                int weight = edge.second;
                
                min_score = min(min_score, weight);
                
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        return min_score;
    }
};