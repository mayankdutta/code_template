//not optmize
#include <bits/stdc++.h>
#include <iomanip>

using ll=long long int; 
using lld=long double; 

class Info { 
    lld C; 
    lld low, high;
    public: 

    Info ( ) { 
        std::cin >> C; 
        low = 0; 
        high = C; 
    }

    void pseudo_main ( ) { 
        bool flag = false; 
        for ( int test = 0; test <= 200; test ++ ) { 
            lld mid = ( high + low ) / 2; 
            //std::cout << low << " " << mid << " " << high << "\n"; 

            if ( good ( mid ) == 1 ) { 
                std::cout << std::setprecision ( 20 ) << mid << "\n"; 
                flag = true;
                break;
            }

            if ( good ( mid ) == 0 ) { 
                low = mid; 
            }

            if ( good ( mid ) == -1 ) { 
                high = mid; 
            }
        }
        if ( !flag ) { 
            std::cout << std::setprecision ( 20 ) << low << "\n"; 
        }
    }

    int good ( lld mid ) { 
        lld exp = mid * mid + sqrt ( mid ); 
        //std::cout << std::setprecision ( 20 ) << exp << " < ---- \n";

        if ( exp == C ) { 
            //std::cout << "returned 1 \n"; 
            return 1; 
        }
        else if ( exp < C ) {
            //std::cout << "returned < \n"; 
            return 0; 
        }
        else {
            //std::cout << "returned else \n"; 
            return -1; 
        }
    }
};

int main ( ) { 
    Info i; 
    i.pseudo_main ( ); 
}

