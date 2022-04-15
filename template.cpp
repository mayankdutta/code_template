/* THINK ALOUD !! */
#include <algorithm>
// #include <bits/stdc++.h>
#include <chrono>
#include <climits>
#include <cmath>
#include <random>

#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define debug(x) std::cout << " -> [ " << #x << " = " << x << "]\n"
#define debug2(x, y)                                                           \
  std::cout << " -> [ " << #x << " = " << x << " , " << #y << " = " << y       \
            << " ]\n"
#define debug3(x, y, z)                                                        \
  std::cout << " -> [ " << #x << " = " << x << " , " << #y << " = " << y       \
            << " , " << #z << " = " << z << " ]\n";
#define debug4(x, y, z, a)                                                     \
  std::cout << " -> [ " << #x << " = " << x << " , " << #y << " = " << y       \
            << " , " << #z << " = " << z << " , " << #a << " = " << a          \
            << " ]\n";
#define debug5(x, y, z, a, b)                                                  \
  std::cout << " -> [ " << #x << " = " << x << " , " << #y << " = " << y       \
            << " , " << #z << " = " << z << " , " << #a << " = " << a << " , " \
            << #b << " = " << b << " ]\n";
#define debug6(x, y, z, a, b, c)                                               \
  std::cout << " -> [ " << #x << " = " << x << " , " << #y << " = " << y       \
            << " , " << #z << " = " << z << " , " << #a << " = " << a << " , " \
            << #b << " = " << b << " , " << #c << " = " << c << " ]\n";

using namespace std;
using namespace std::chrono;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;

// /*
//  * null_type means we wish to use set, if we want to use map, use mapped_type
//  *
//  * less : It is the basis for comparison of two functions.
//  *
//  * rb_tree_tag: type of tree used, here it is red black tree.
//  *
//  * tree_order_statistics_node__update : It is included in tree_policy.hpp and
//  * contains various operations for updating the node variants of a tree-based
//  * container, so we can keep track of metadata like the number of nodes in a
//  * subtree
//  */

// /*
//  * ADDITIONAL FUNCTION
//  * find_by_order(k): returns iterator to the kth element
//  *
//  * order_of_key(k) : returns number of items that are strictly smaller
//  * than our item k.
//  */

// template <class INT>
// using ordered_set = tree<INT, null_type, std::less<INT>, rb_tree_tag,
//                          tree_order_statistics_node_update>;

// template <class INT>
// using rordered_set = tree<INT, null_type, std::greater<INT>, rb_tree_tag,
//                           tree_order_statistics_node_update>;

// template <class INT>
// using multi_ordered_set = tree<INT, null_type, std::less_equal<INT>,
//                                rb_tree_tag,
//                                tree_order_statistics_node_update>;

// template <class INT>
// using rmulti_ordered_set = tree<INT, null_type, std::greater_equal<INT>,
//                                 rb_tree_tag,
//                                 tree_order_statistics_node_update>;

#define ll long long int
#define lld long double

#define vi std::vector<int>
#define vb std::vector<bool>
#define vc std::vector<char>
#define vd std::vector<double>
#define vlld std::vector<lld>
#define vll std::vector<ll>

#define vvi std::vector<vi>
#define vvb std::vector<vb>
#define vvc std::vector<vc>
#define vvd std::vector<vd>
#define vvlld std::vector<vlld>
#define vvll std::vector<vll>

#define pii std::pair<int, int>
#define pll std::pair<ll, ll>
#define pci std::pair<char, int>
#define pic std::pair<int, char>
#define pls std::pair<ll, std::string>
#define psl std::pair<std::string, ll>
#define pis std::pair<int, std::string>
#define psi std::pair<std::string, int>

#define vpii std::vector<pii>
#define vpll std::vector<pll>
#define vpci std::vector<pci>
#define vpic std::vector<pic>
#define vpls std::vector<pls>
#define vpsl std::vector<psl>
#define vpis std::vector<pis>
#define vpsi std::vector<psi>

#define vvpii std::vector<vpii>
#define vvpll std::vector<vpll>
#define vvpci std::vector<vpci>
#define vvpic std::vector<vpic>
#define vvpls std::vector<vpls>
#define vvpsl std::vector<vpsl>
#define vvpis std::vector<vpis>
#define vvpsi std::vector<vpsi>

#define pb push_back
#define accu accumulate

#define x first
#define y second

#define fast                                                                   \
  std::ios_base::sync_with_stdio(0);                                           \
  std::cin.tie(0);

#define rep(i, a, n) for (ll i = a; i < n; i++)
#define per(i, a, n) for (ll i = n - 1; i >= a; i--)
#define repp(i, a, n, p) for (ll i = a; i < n; i += p)
#define all(c) (c).begin(), (c).end()
#define lla(c) (c).rbegin(), (c).rend()
#define mod 1000000007
#define INF (long long int)1e18
#define inf (int)1e9

/*********** operator overloadings ************/

/* To print vector, cout << {name_of_vector}*/
template <typename T>
ostream &operator<<(ostream &COUT, const std::vector<T> &v) {
  COUT << "[";
  for (int i = 0; i < (int)v.size(); ++i) {
    if (i)
      COUT << ", ";
    COUT << v[i];
  }
  COUT << "]\n";
  return COUT;
}

template <typename T>
ostream &operator<<(ostream &COUT, const std::deque<T> &v) {
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
template <typename T> ostream &operator<<(ostream &COUT, const std::set<T> &v) {
  COUT << "{";
  for (auto it : v) {
    COUT << it;
    if (it != *v.rbegin())
      COUT << ", ";
  }
  COUT << "}\n";
  return COUT;
}

template <typename T>
ostream &operator<<(ostream &COUT, const std::unordered_set<T> &v) {
  COUT << "{";
  for (auto it : v) {
    COUT << it;
    if (it != *v.rbegin())
      COUT << ", ";
  }
  COUT << "}\n";
  return COUT;
}

template <typename T>
ostream &operator<<(ostream &COUT, const std::multiset<T> &v) {
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
ostream &operator<<(ostream &COUT, const std::map<T, S> &v) {
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
ostream &operator<<(ostream &COUT, const std::pair<T, S> &v) {
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

template <typename INT>
ostream &operator<<(ostream &COUT, priority_queue<INT> pq) {
  COUT << " -> ";
  for (; !pq.empty(); pq.pop())
    COUT << pq.top() << ' ';

  COUT << "| \n";
  return COUT;
}

template <typename INT>
ostream &operator<<(ostream &COUT,
                    priority_queue<INT, vector<INT>, greater<INT>> pq) {
  COUT << " -> ";
  for (; !pq.empty(); pq.pop())
    COUT << pq.top() << ' ';

  COUT << "| \n";
  return COUT;
}

/* Reading vector */
template <typename T>
inline istream &operator>>(istream &CIN, std::vector<T> &arr) {
  for (auto &x : arr)
    CIN >> x;
  return CIN;
}

/*********** Number theory ************/

template <typename INT> INT GCD(INT a, INT b) { return b ? GCD(b, a % b) : a; }
template <typename INT> INT LCM(INT a, INT b) { return a / GCD(a, b) * b; }

template <typename INT> std::map<INT, int> factorize(INT n) {
  map<INT, int> mp;
  for (INT i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      n /= i;
      mp[i]++;
    }
  }

  if (n > 1)
    mp[n] += 1;
  return mp;
}

ll bin_pow(ll a, ll b) {
  if (b == 0)
    return 1;
  long long res = bin_pow(a, b / 2);
  if (b % 2)
    return res * res * a;
  return res * res;
}

int digits(ll i) { return i > 0 ? (int)log10((double)i) + 1 : 1; }

#define primeSize 2000000

vector<bool> isPrime(primeSize, true);
vector<int> arePrimes;
void make_seive() {
  isPrime[0] = false;
  isPrime[1] = false;

  for (int i = 2; i <= sqrt(primeSize); i++)
    if (isPrime[i])
      for (int j = i * 2; j <= primeSize; j += i)
        isPrime[j] = false;

  for (int i = 2; i < primeSize; i++)
    if (isPrime[i])
      arePrimes.push_back(i);
}

void initiate(std::string name = "") {
  fast;
  /* make_seive(); */
  if (!name.empty()) {
    freopen((name + ".in").c_str(), "r", stdin); // see Input & Output
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

/*********** Disjoint union find, dsu ************/

class UnionFind {
public:
  std::vector<int> Parent;
  std::vector<int> Size;

  void init(int n) {
    /* You may want to change the size. */
    Size.resize(int(3e5) + 5, 1);
    Parent.resize(int(3e5) + 5, 0);

    for (int i = 0; i < n; i++)
      add(i);
  }

  void add(int n) {
    Parent[n] = n;
    Size[n] = 1;
  }

  int find(int i) {
    return (Parent[i] == i) ? i : (Parent[i] = find(Parent[i]));
  }

  bool is_same(int i, int j) { return find(i) == find(j); }

  void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
      return;
    if (Size[a] < Size[b])
      std::swap(a, b);

    Parent[b] = a;
    Size[a] += Size[b];
  }
} dsu;

/*********** Bitset ************/

template <typename INT>
std ::vector<INT> to_binary(const INT &n, int Size = 31) {
  vector<INT> ans;
  for (int i = Size; i >= 0; i--)
    ans.push_back(((n >> i) & 1));
  return ans;
}

unsigned int next_power_of_two(unsigned int v) {
  /* compute the next highest power of 2 of 32-bit v */
  v--;
  v |= v >> 1; // v >> 2 means, v/4, shifting rightward twice, 1000100 -> 10001
  v |= v >> 2;
  v |= v >> 4;
  v |= v >> 8;
  v |= v >> 16;
  v++;
  return v;
}

template <typename INT> INT get_random(INT start_index, INT end_index) {
  std::random_device dev;
  std::mt19937 rng(dev());
  // distribution in range [start_index, end_index]
  std::uniform_int_distribution<std::mt19937::result_type> dist6(start_index,
                                                                 end_index);
  return dist6(rng);
}

void solve() {}

int main() {
  auto start = high_resolution_clock::now();

  initiate();
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cerr << "Time taken by function: " << ceil(duration.count() / 1000.0)
       << " milliseconds" << '\n';
}

/*
Tips:
   -- for queries involving sum using queue or minimum sum of size k, do also
   consider prefix sum.

   Build and running
   g++ --std=c++17 -Wall -Wextra -Wshadow -fsanitize=undefined
   -fsanitize=address FILE.cpp && ./a.out < in

   Naming
   -for types (class/struct name) UpperCamelCase: Point, Info, SegTree
   -functions and variable lowerCamelCase: someMethod, someVariable
   -MACROS and constants all capital letters separated by _ : SOME_MACRO, MAX_N,
   MOD

*/
