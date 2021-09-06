#include <algorithm>
#include <iostream>
#include <vector>

using ll = long long int;

int main() {
  ll N, M;
  // N for no. of elements, M for queries
  scanf("%lld %lld", &N, &M);

  std::vector<ll> arr(N, 0);
  for (ll i = 0; i < M; i++) {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    a--;
    b--;

    arr[a] += 1;
    arr[b + 1] -= 1;
  }

  std::vector<ll> original;
  ll sum = 0;
  for (ll i = 0; i < N; i++) {
    sum += arr[i];
    original.push_back(sum);
  }

  ll count = 0;
  for (ll i = 0; i < N; i++) {
    // printf ("%lld ", original[i]);
    if (original[i] == M) {
      // printf ("%lld ", original[i]);
      count++;
    }
  }
  printf("%lld\n", count);
}
