//THINK ALOUD !! 
#include <bits/stdc++.h>
#define what_is(x) cout << "value of " << #x << " :: " << x << "\n" 

using namespace std;
using ll=long long int;
using lld=long double;
#define mp make_pair
#define pb push_back
#define accu accumulate 

#define pll pair<ll,ll>
#define pii pair<int,int> 
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

ll bin_pow (ll a, ll b) {
    if (b == 0) return 1;
    long long res = bin_pow(a, b / 2);
    if (b % 2) return res * res * a;
    else return res * res;
}

template <typename t> inline void print (const t & v){
    for (const auto & i: v) {
        std::cout << i << " ";
    }
    std::cout << '\n';
}

int digit (ll i) { 
    return i > 0 ? (int) log10 ((double) i) + 1 : 1;
}

int main ( ) { 
    fast; 
    cout << "Hello, World\n"; 
}
