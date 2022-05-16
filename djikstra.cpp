  vector<int> dijkstra(int n, vector<vector<int>> adj[], int source) {
    vector<int> dist(n + 1, 1e9);

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    pq.push({0, source});
    dist[source] = 0;

    while (!pq.empty()) {
      int updated_distance_of_from = pq.top().first;
      int from = pq.top().second;
      pq.pop();

      if (updated_distance_of_from > dist[from]) {
        continue;
      }

      for (const auto &v : adj[from]) {
        int to = v[0];
        int distance_till_to = v[1];

        if (distance_till_to + dist[from] < dist[to]) {
          dist[to] = distance_till_to + dist[from];
          pq.push({dist[to], to});
        }
      }
    }
    return dist;
  }
