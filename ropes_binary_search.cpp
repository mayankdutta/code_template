#include <iostream>
#include <vector> 
#include <algorithm>
#include <iomanip>

using ll=long long int; 
using lld=long double;

class Info { 
    ll N, K; 
    std::vector <ll> arr; 
    lld low, high;

    public: 

    Info ( ) { 
        std::cin >> N >> K; 
        arr.resize ( N ); 

        for ( ll i=0; i<N; i++ ) { 
            std::cin >> arr[i]; 
        }

        low  = 0; // storing good elements, as they are in left side, always return TRUE
        high = 1e8;  // choosen as maxmium
    }

    void pseudo_main ( ) { 
        for ( int test = 0; test < 100; test ++ ) { 
            lld mid = ( low + ( high - low ) / 2 ); 
            if ( good ( mid ) ) low = mid;  // according to our orientation 1's are in left side because 
            // 0 is satisfying our conditions hence we have to show the maximum left_est 1

            else high = mid;  // if we getting !good elements 
        }
        std::cout << std::setprecision ( 10 ) << low << "\n";  // was important 
    }

    bool good ( lld mid ) { 
        ll count = 0; 
        for ( ll i=0; i<N; i++ ) {
            count += arr[i] / mid; 
        }
        return count >= K; 
    }
}; 

int main ( ) { 
    Info i;
    i.pseudo_main ( ); 
}

