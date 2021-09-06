#include <iostream>
using ll = long long int;

ll kadane(const vector<ll> arr) {
  ll best = 0, mx = 0;
  for (ll i = 0; i < arr.size(); i++) {
    mx = std::max(arr[k], arr[k] + mx);
    best = std::max(best, mx);
  }
  return best;
}
