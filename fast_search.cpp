/* Problem statement 

 Fast search 
 Given an array find how many elements b/w L and R 
 */

#include <iostream>
#include <algorithm>
#include <vector>

using ll=long long int; 

ll closestToLeft ( ll arr[], ll N, ll K ) {  // will search for element <=K [from LEFT till K]
    ll left = -1; 
    ll right = N;

    while ( right > left + 1 ) { 
        ll mid = ( left + right ) / 2; 
        if ( arr[mid] > K ) right = mid; 
        else left = mid; 
    }

    return left + 1; 
}

ll closestToRight ( ll arr[], ll N, ll K ) {  // will search for element >=K [from RIGHT till K] 
    ll left = -1; 
    ll right = N; 

    while ( right > left + 1 ) { 
        ll mid = ( left + right ) / 2; 
        if ( arr[mid] < K ) left = mid; 
        else right = mid; 
    }
    return right + 1;
}

int main () { 
    ll N, K; 
    scanf ( "%lld", &N); 

    ll arr[N]; 
    for ( ll i=0; i<N; i++ ) scanf ( "%lld", &arr[i]); 
    scanf ( "%lld", &K ); 
    std::sort ( arr, arr + N );

    while ( K-- ) { 
        ll A, B;
        scanf ( "%lld %lld", &A, &B );
        std::cout << closestToLeft ( arr, N, B ) - closestToRight ( arr, N, A ) + 1 << "\n"; 
    }
}
