/* THINK ALOUD !! */
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <cmath>
#include <stack>
#include <vector>

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

using namespace std;
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
#define primeSize 2000000

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

/* Reading vector */
template <typename T> inline istream &operator>>(istream &CIN, vector<T> &a) {
  for (auto &x : a)
    CIN >> x;
  return CIN;
}

template <typename INT> INT GCD(INT a, INT b) {
  /* if (b == 0) return a; */
  /* return gcd(b, a%b); */
  return b ? GCD(b, a % b) : a;
}

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

void setIO(std::string name = "") {
  /* name is nonempty for USACO file I/O */
  /* ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output */
  /* alternatively, cin.tie(0)->sync_with_stdio(0); */
  if (!name.empty()) {
    freopen((name + ".in").c_str(), "r", stdin); // see Input & Output
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

ll bin_pow(ll a, ll b) {
  if (b == 0)
    return 1;
  long long res = bin_pow(a, b / 2);
  if (b % 2)
    return res * res * a;
  return res * res;
}

int totalDigits(ll i) { return i > 0 ? (int)log10((double)i) + 1 : 1; }

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

void solve() {}

int main() {
  /* setIO(); */
  /* make_seive(); */
  fast;
  int t = 1;
  cin >> t;
  while (t--)
    solve();
  /* cout << "Hello, World\n"; */
}

/*
Tips:
-- for queries involving sum using queue or minimum sum of size k, do also
consider prefix sum.
*/

/*
   Build and running
   g++ --std=c++17 -Wall -Wextra -Wshadow -fsanitize=undefined
   -fsanitize=address FILE.cpp && ./a.out < in

   Naming
   -for types (class/struct name) UpperCamelCase: Point, Info, SegTree
   -functions and variable lowerCamelCase: someMethod, someVariable
   -MACROS and constants all capital letters separated by _ : SOME_MACRO, MAX_N,
   MOD

*/
