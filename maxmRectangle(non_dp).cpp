#include <iostream>
#include <vector> 
#include <algorithm>

using ll=long long int; 

class Info { 
    ll n, w, h; 
    public:

    Info () { 
        scanf ( "%lld %lld %lld", &w, &h, &n );
    }

    void pseudo_main () { 
        ll left = 0; // bad no. 
        ll right = 1;  // good no. 

        while ( !good ( right ) ) right *= 2; 

        //std::cout << w << " " << h << " " << n << "\n"; 
        while ( right > left + 1 ) {  // Do note type of binary_search we are using 
            ll mid = ( left + ( right - left ) / 2 ); 
            if ( good ( mid ) ) right = mid; 
            else left = mid; 
        }

        printf ( "%lld\n", right ); 
    }

    bool good ( ll number ) {
        // intentionally put like this 
        return ( number / w ) * ( number / h ) >= n; 
    }

};

int main () { 
    //class formed to avoid global variables 
    Info i; 
    i.pseudo_main (); 

}
