#include <stdint.h>


uint64_t count_trailing_zeros(uint64_t v) {
    if(v & 0x1){
        return 0;
    }
    
    if((v & 0x7) == 0){
        return 3;
    }

    if((v & 0x3) == 0){
        return 2;
    }else{
        return 1;
    }
}


uint64_t collatz_orbit(uint64_t n, uint64_t k){
    uint64_t x;

    for(;k>2;k=k-3){
        if(n<17){
            break;
        }

        x = count_trailing_zeros(n);

        switch(x){
            case 0:
                if(n>=6148914691236517205){
                return 0;
                }
                x = (3*n+1) >> 1;
                if(x%2==0){
                    n = x>>1;
                }else{
                    if(x>=6148914691236517205){
                        return 0;
                    }
                    n = 3*x+1;
                }
                break;
            case 1:
                n = (n>>1);
                if(n>=6148914691236517205){
                        return 0;
                }
                n = (3*n + 1) >> 1;
                break;
            case 2:
                n = 3*(n>>2) +1;
                break;
            default:
                n = n >> 3;
                break;
        }
    }


    for(;k>0;k--){
        if(n==1){
            switch(k%3){
                case 0:
                    return 1;
                break;

                case 1:
                    return 4;
                break;

                case 2:
                    return 2;
                break;
            }
        }

        x = count_trailing_zeros(n);
        if(x>0){
            if(k>x){
                n = n >> x--;
                k = k - x;
            }else{
                n = n >> k;
                return n;
            }
        }else{
            if(n>=6148914691236517205){
                return 0;
            }

            if(k!=1){
                n = ((3*n) + 1) >> 1;
                k--;
            }else{
                n = (3*n) + 1;
            }
            
        }
    }
    return n;

}