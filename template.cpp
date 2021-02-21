//THINK ALOUD !! 
#include <bits/stdc++.h>
#define debug(x) cout << " -> [ " << #x << " = " << x << "]\n" 
#define debug2(x, y) cout << " -> [ " << #x << " = " << x << " , " << #y << " = " << y << " ]\n"
#define debug3(x, y, z) cout << " -> [ " << #x << " = " << x << " , " << #y << " = " << y << " , " << #z << " = " << z << " ]\n";
#define debug4(x, y, z, xx) cout << " -> [ " << #x << " = " << x << " , " << #y << " = " << y << " , " << #z << " = " << z << " , " << #xx << " = " << xx << " ]\n";

using namespace std;
using ll=long long int;
using lld=long double;
#define mp make_pair
#define pb push_back
#define accu accumulate 

#define pll pair<ll, ll>
#define pii pair<int, int> 
#define pci pair<char, int> 
#define pic pair<int, char> 
#define pls pair<ll, string>
#define psl pair<string, ll>
#define pis pair<int, string>
#define psi paid<string, int>
// #define x first 
// #define y second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


#define rep(i, a, n) for (ll i = a; i < n; i++)
#define per(i, a, n) for (ll i = n-1; i >= a; i--)
#define repp(i, a, n, p) for (ll i = a; i < n; i += p)
#define all(c) (c).begin(), (c).end()
#define lla(c) (c).rbegin(), (c).rend()
#define print_arr(arr, n) for (int i = 0; i < n; i++) std::cout << arr[i] << ' '; std::cout << '\n';
#define mod 1000000007
#define primeSize 2000000

template <typename t> inline void print(const t & v) {
    for (const auto& i : v) {
        std::cout << i << " ";
    } std::cout << '\n';
}

template <typename t> inline void printt(const t & v) { 
    for (const auto& i : v) { 
        std::cout << i.first << " " << i.second << '\n';
    } std::cout << '\n';
}

template <typename INT> INT gcd(INT a, INT b) { 
    if (b == 0) return a; 
    return gcd(b, a%b); 
}

template <typename INT> std::map<INT, int> factorize(INT n) { 
    map<INT, int> mp; 
    for (INT i = 2; i * i <= n; i++) { 
        while (n % i == 0) { 
            n /= i; 
            mp[i] ++;
        }
    }

    if (n > 1) mp[n] += 1;
    return mp;
}

ll bin_pow(ll a, ll b) {
    if (b == 0) return 1;
    long long res = bin_pow(a, b / 2);
    if (b % 2) return res * res * a;
    else return res * res;
}

int totalDigits(ll i) { 
    return i > 0 ? (int) log10 ((double) i) + 1 : 1;
}

vector<bool> isPrime(primeSize, true);
vector<int> arePrimes;
void make_seive() { 
    isPrime[0] = false; 
    isPrime[1] = false; 

    for (int i = 2; i <= sqrt(primeSize); i++) { 
        if (isPrime[i]) { 
            for (int j = i * 2; j <= primeSize; j += i) { 
                isPrime[j] = false; 
            }
        }
    }

    for (int i = 2; i < primeSize; i++) { 
        if (isPrime[i]) { 
            arePrimes.push_back(i); 
        }
    }
}


void solve() { 

}

int main() { 
    fast; 
    int t = 1;
    //make_seive();
    //cin >> t;
    while (t--) 
        solve(); 
    cout << "Hello, World\n"; 
}

/*
Tips:
-- for queries involving sum using queue or minimum sum of size k, do also consider prefix sum. 
*/

/*
Build and running
g++ --std=c++17 -Wall -Wextra -Wshadow -fsanitize=undefined -fsanitize=address FILE.cpp && ./a.out < in 

Naming 
-for types (class/struct name) UpperCamelCase: Point, Info, SegTree 
-functions and variable lowerCamelCase: someMethod, someVariable 
-MACROS and constants all capital letters separated by _ : SOME_MACRO, MAX_N, MOD

*/
