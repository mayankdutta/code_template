#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

const ll INF = 1e15;
const ll NINF = -1e15;

int main() {
  int n, m;
  cin >> n >> m;

  vector<tuple<ll, ll, ll>> edges(m);
  for (auto &[from, to, dist] : edges) {

    cin >> from >> to >> dist;
    dist *= -1;
  }

  for (auto &[from, to, dist] : edges) {
    cout << from << ' ' << to << ' ' << dist << '\n';
  }
  cout << "\n\n";

  vector<ll> dist(n + 1, INF);

  dist[1] = 0;

  bool relaxed = true;
  for (int i = 1; i <= n && relaxed; i++) {
    relaxed = false;
    for (auto &[from, to, w] : edges) {
      if (dist.at(from) == INF)
        continue;
      relaxed = true;
      if (dist.at(from) + w < dist.at(to)) {
        dist.at(to) = dist.at(from) + w;
      }
    }
  }

  relaxed = true;
  for (int i = 1; i <= n && relaxed; i++) {
    relaxed = false;
    for (auto &[from, to, w] : edges) {
      if (dist.at(from) == INF)
        continue;
      relaxed = true;
      if (dist.at(from) + w < dist.at(to)) {
        dist.at(to) = NINF;
      }
    }
  }

  if (dist[n] == NINF) {
    cout << -1 << '\n';
  } else {
    cout << -1 * dist[n] << '\n';
  }
}
