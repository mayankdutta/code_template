// https://leetcode.com/problems/min-cost-to-connect-all-points/

class Solution {
    public:
    vector<int> used; 
    vector<vector<pair<int, int>>> Adj;
    
    priority_queue<pair<int, int>, 
                   vector<pair<int, int>>, 
                   greater<pair<int, int>>> pq;

    int distance(vector<int> &one, vector<int> &two) {
        return abs(one[0] - two[0]) + abs(one[1] - two[1]);
    }


    void process(int u) {
        used[u] = 1;
        for (int j = 0; j < Adj[u].size(); j++) {
            auto [v, w] = Adj[u][j];
            if (!used[v]) {
                pq.push({w, v});
            }
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        Adj.resize(n + 1);
        used.resize(n + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                Adj[i].push_back({j, distance(points[i], points[j])});
            }
        }
        
        process(0);
        int ans = 0;
        
        while (!pq.empty()) {
            auto [w, u] = pq.top(); 
            pq.pop();
            
            // cout << u << ' '<< w << '\n';
            if (!used.at(u)) {
                ans += w; 
                process(u);
            }
        }
        return ans;

    }
};
