#include <stdint.h>

int ean13(uint64_t ean) {
    if(ean>9999999999999){
        return 0;
    }
      register int sum = 0;

        sum +=(ean % 10);  //0
        ean /= 10;
        sum += 3 * (ean % 10); //1 
        ean /= 10;
        sum +=(ean % 10);  //2
        ean /= 10;
        sum += 3 * (ean % 10);  //3
        ean /= 10;
        sum +=(ean % 10);  //4
        ean /= 10;
        sum += 3 * (ean % 10);  //5
        ean /= 10;
        sum +=(ean % 10);  //6
        ean /= 10;
        sum += 3 * (ean % 10);  //7
        ean /= 10;
        sum +=(ean % 10);  //8
        ean /= 10;
        sum += 3 * (ean % 10); //9 
        ean /= 10;
        
        
        if(ean==0){
          return sum%10==0; //terminate early
        }


        sum +=(ean % 10);  //10
        ean /= 10;
        sum += 3 * (ean % 10); //11
        ean /= 10;
        sum +=(ean % 10);  //12
        ean /= 10;
      return sum%10==0;
    }

