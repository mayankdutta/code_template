#include <bits/stdc++.h>
using ll = long long int;
using lld = long double;

#define mp make_pair
#define pb push_back
#define accu accumulate

#define vi std::vector<int>
#define vb std::vector<bool>
#define vc std::vector<char>
#define vd std::vector<double>
#define vlld std::vector<long double>
#define vll std::vector<long long int>

#define vvi std::vector<std::vector<int>>
#define vvb std::vector<std::vector<bool>>
#define vvc std::vector<std::vector<char>>
#define vvd std::vector<std::vector<double>>
#define vvlld std::vector<std::vector<long double>>
#define vvll std::vector<std::vector<long long int>>

#define pll std::pair<ll, ll>
#define pii std::pair<int, int>
#define pci std::pair<char, int>
#define pic std::pair<int, char>
#define pls std::pair<ll, std::string>
#define psl std::pair<std::string, ll>
#define pis std::pair<int, std::string>
#define psi std::pair<std::string, int>

#define vpll std::vector<std::pair<ll, ll>>
#define vpii std::vector<std::pair<int, int>>
#define vpci std::vector<std::pair<char, int>>
#define vpic std::vector<std::pair<int, char>>
#define vpls std::vector<std::pair<ll, std::string>>
#define vpsl std::vector<std::pair<std::string, ll>>
#define vpis std::vector<std::pair<int, std::string>>
#define vpsi std::vector<std::pair<std::string, int>>
#define x first
#define y second

#define fast                                                                   \
  std::ios_base::sync_with_stdio(0);                                           \
  std::cin.tie(0);

#define INF (int)1e9 // for INT_MAX which still allows for INF + INF
#define rep(i, a, n) for (ll i = a; i < n; i++)
#define per(i, a, n) for (ll i = n - 1; i >= a; i--)
#define repp(i, a, n, p) for (ll i = a; i < n; i += p)
#define all(c) (c).begin(), (c).end()
#define lla(c) (c).rbegin(), (c).rend()
#define mod 1000000007

#define debug(x) cout << " -> [ " << #x << " = " << x << "]\n"
#define debug2(x, y)                                                           \
  cout << " -> [ " << #x << " = " << x << " , " << #y << " = " << y << " ]\n"
#define debug3(x, y, z)                                                        \
  cout << " -> [ " << #x << " = " << x << " , " << #y << " = " << y << " , "   \
       << #z << " = " << z << " ]\n";
#define debug4(x, y, z, xx)                                                    \
  cout << " -> [ " << #x << " = " << x << " , " << #y << " = " << y << " , "   \
       << #z << " = " << z << " , " << #xx << " = " << xx << " ]\n";
#define debug5(x, y, z, xx, yy)                                                \
  cout << " -> [ " << #x << " = " << x << " , " << #y << " = " << y << " , "   \
       << #z << " = " << z << " , " << #xx << " = " << xx < < < <              \
      " , " << #yy < < < < " = " << yy << " ]\n";

/* To print vector, cout << {name_of_vector}*/
template <typename T> ostream &operator<<(ostream &COUT, const vector<T> &v) {
  COUT << "[";
  for (int i = 0; i < (int)v.size(); ++i) {
    if (i)
      COUT << ", ";
    COUT << v[i];
  }
  COUT << "]\n";
  return COUT;
}

template <typename T> ostream &operator<<(ostream &COUT, const deque<T> &v) {
  COUT << "[";
  for (int i = 0; i < (int)v.size(); ++i) {
    if (i)
      COUT << ", ";
    COUT << v[i];
  }
  COUT << "]\n";
  return COUT;
}

/* To print set, cout << {name_of_set}*/
template <typename T> ostream &operator<<(ostream &COUT, const set<T> &v) {
  COUT << "{";
  for (auto it : v) {
    COUT << it;
    if (it != *v.rbegin())
      COUT << ", ";
  }
  COUT << "}\n";
  return COUT;
}

template <typename T> ostream &operator<<(ostream &COUT, const multiset<T> &v) {
  COUT << "{";
  for (auto it : v) {
    COUT << it;
    if (it != *v.rbegin())
      COUT << ", ";
  }
  COUT << "}\n";
  return COUT;
}

/* To print map, cout << {name_of_map}*/
template <typename T, typename S>
ostream &operator<<(ostream &COUT, const map<T, S> &v) {
  COUT << "{\n";
  for (auto it : v) {
    COUT << "    (" << it.first << " : " << it.second << ")";
    if (it != *v.rbegin())
      COUT << ",\n";
  }
  COUT << "\n}\n";
  return COUT;
}

/* To print pair, cout << {name_of_pair}*/
template <typename T, typename S>
ostream &operator<<(ostream &COUT, const pair<T, S> &v) {
  COUT << "(";
  COUT << v.first << ", " << v.second << ")";
  return COUT;
}

template <typename T, typename S>
ostream &operator<<(ostream &COUT, const std::vector<std::pair<T, S>> &arr) {
  COUT << "{\n";
  for (const auto &v : arr) {
    COUT << "(";
    COUT << v.first << ", " << v.second;
    if (v != *arr.rbegin())
      COUT << ",\n";
  }
  COUT << "\n}\n";
  return COUT;
}
