#include <iostream>
#include <map>
#include <vector>
using ll=long long int; 

int main () { 

    ll N;
    scanf ("%lld", &N); 

    std::map <ll, std::pair <ll, ll> > mp; 

    ll sum = 0;
    for (ll i=0; i<N; i++) { 
        ll A, B; 
        scanf ("%lld %lld", &A, &B); 

        mp [A].first += 1; 
        mp [B+1].first -= 1; 

        sum += mp[A].first; 
        mp [A].second = sum; 
    }

    ll ans = 0, year = 0;
    for (auto i: mp) { 
        if ( ans < i.second.second ) { 
            ans = i.second.second; 
            year = i.first; 
        }
    }

    printf ("%lld %lld\n", year, ans); 
}


