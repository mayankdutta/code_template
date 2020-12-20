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
#define mod 1000000007

class Bignum {
    public:
        Bignum(int value) {
            assert(value >= 0 && value <= 999999999);
            parts.push_back(value);
        }

        Bignum& operator*=(int rhs) {
            assert(rhs >= 0 && rhs <= 999999999);
            uint32_t carry = 0;
            for (size_t i = 0; i < parts.size(); i++) {
                uint64_t product = (uint64_t)parts[i] * (uint64_t)rhs + carry;
                parts[i] = (uint32_t)(product % 1000000000LL);
                carry = (uint32_t)(product / 1000000000LL);
            }
            if (carry != 0) parts.push_back(carry);
            return *this;
        }

        friend std::ostream & operator<<(std::ostream& stream, const Bignum& num);

    private:
        std::vector<uint32_t> parts;
};

inline std::ostream& operator<<(std::ostream& stream, const Bignum& num) {
    char oldfill = stream.fill('0');
    for (std::vector<uint32_t>::const_reverse_iterator it = num.parts.rbegin(); it != num.parts.rend(); it++)
        stream << *it << std::setw(9);
    stream.fill(oldfill);
    stream.width(0);
    return stream;
}

Bignum factorial(int n) {
    Bignum fac = 1;
    for (int i = 2; i <= n; i++) fac *= i;
    return fac;
}

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

string dec_to_bin (int n) { 
    string binary = std::bitset <8> ( n ).to_string ( ); 
    return binary; 
}

unsigned long bin_to_dec (string s) { 
    unsigned long decimal = std::bitset <8> ( s ).to_ulong ( ); 
    return decimal;
}

unsigned int next_power_of2 (unsigned int v) { 
    //    unsigned int v; // compute the next highest power of 2 of 32-bit v
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v; 
}

int digit (ll i) { 
    return i > 0 ? (int) log10 ((double) i) + 1 : 1;
}

int main ( ) { 
    fast; 
    cout << "Hello, World\n"; 
}
