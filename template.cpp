//THINK ALOUD !! 
#include <bits/stdc++.h>
#define what_is(x) cout << " -> [ " << #x << " = " << x << "]\n" 
#define what_iss(x, y) cout << " -> [ " << #x << " = " << x << " , " << #y << " = " << y << " ]\n"  

using namespace std;
using ll=long long int;
using lld=long double;
#define mp make_pair
#define pb push_back
#define accu accumulate 

#define pll pair<ll,ll>
#define pii pair<int,int> 
#define pci pair<char,int> 
#define pic pair<int,char> 
#define pls pair<ll,string>
#define psl pair<string,ll>
#define pis pair<int,string>
#define psi paid<string,int>
#define x first 
#define y second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


#define rep( i, a, n ) for( ll i=a; i<n; i++)
#define per( i, a, n ) for( ll i=n-1; i>=a; i--)
#define repp( i, a, n, p ) for( ll i=a; i<n; i+=p)
#define all(c) (c).begin(), (c).end()
#define lla(c) (c).rbegin(), (c).rend()
#define mod 1000000007
#define Size 2000000

template <typename t> inline void print (const t & v) {
    for (const auto & i: v) {
        std::cout << i << " ";
    } std::cout << '\n';
}

template <typename t> inline void printt (const t & v) { 
    for (const auto &i: v) { 
        std::cout << i.first << " " << i.second << '\n';
    } std::cout << '\n';
}

ll bin_pow (ll a, ll b) {
    if (b == 0) return 1;
    long long res = bin_pow(a, b / 2);
    if (b % 2) return res * res * a;
    else return res * res;
}

int digit (ll i) { 
    return i > 0 ? (int) log10 ((double) i) + 1 : 1;
}

vector <bool> isPrime (Size, true);
void make_seive () { 
    isPrime [0] = false; 
    isPrime [1] = false; 

    for (int i = 2; i <= sqrt (Size); i++) { 
        if (isPrime [i]) { 
            for (int j = i * 2; j <= Size; j += i) { 
                isPrime [j] = false; 
            }
        }
    }
}


void solve () { 

}

int main ( ) { 
    fast; 
    //int t;
    //cin >> t;
    //while (t--) 
        solve (); 
    cout << "Hello, World\n"; 
}

/*
Build and running
g++ --std=c++17 -Wall -Wextra -Wshadow -fsanitize=undefined FILE.cpp && ./a.out < in 

Naming 
-for types (class/struct name) UpperCamelCase: Point, Info, SegTree 
-functions and variable lowerCamelCase: someMethod, someVariable 
-MACROS and constants all capital letters separated by _ : SOME_MACRO, MAX_N, MOD

*/
